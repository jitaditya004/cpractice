#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtHead(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Recursive function to reverse the linked list
void reverseList(struct Node* current) {
    if (current == NULL || current->next == NULL) {
        head = current;
        return;
    }

    reverseList(current->next);
    current->next->next = current;
    current->next = NULL;
}

// Function to print the linked list
void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating a linked list
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtHead(40);

    printf("Original List: ");
    printList();

    // Reversing the list
    reverseList(head);

    printf("Reversed List: ");
    printList();

    return 0;
}