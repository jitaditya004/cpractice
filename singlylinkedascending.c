#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
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

// Function to insert a node in ascending order
void insertInAscendingOrder(int data) {
    struct Node* newNode = createNode(data);
    
    // Case 1: Empty list or new node should be inserted at front
    if (head == NULL || head->data >= data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Insert in the middle or end
    struct Node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to display the list
void displayList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert data (in ascending order)\n");
        printf("2. Display list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertInAscendingOrder(data);
                break;
            case 2:
                displayList();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 0);

    return 0;
}