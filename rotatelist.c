#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
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

// Function to insert a node at the end of the list
void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to rotate the linked list by k positions
void rotateList(int k) {
    if (head == NULL || k == 0) {
        return; // No rotation needed
    }

    // Step 1: Find the length of the list
    struct Node* temp = head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Step 2: Connect the last node to the head, making it a circular list
    temp->next = head;

    // Step 3: Find the node just before the new head
    k = k % length;  // Handle cases where k is greater than length
    int skip = length - k;
    temp = head;
    for (int i = 1; i < skip; i++) {
        temp = temp->next;
    }

    // Step 4: Make the new head and break the circular list
    head = temp->next;
    temp->next = NULL;
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
    // Example: Creating a linked list with integers
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);

    printf("Original list: ");
    printList();

    int k = 2; // Rotate by 2 positions
    rotateList(k);

    printf("List after rotating by %d positions: ", k);
    printList();

    return 0;
}