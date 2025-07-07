#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to print the linked list in reverse
void printReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printReverse(head->next);  // Recursively go to the end of the list
    printf("%d ", head->data); // Print data on returning from recursion
}

// Function to add a node at the end of the linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Main function to test the reverse traversal
int main() {
    struct Node* head = NULL;

    // Append nodes to the list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Linked list in reverse order: ");
    printReverse(head);
    printf("\n");

    return 0;
}
