#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function to insert a node at a random position
void insertAtRandom(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If inserting at the head
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at a random position
void deleteAtRandom(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    // If deleting the head node
    if (position == 1) {
        head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Function to display the list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the list
void reverse() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    // Insert elements
    insertAtRandom(10, 1);  // Insert 10 at position 1
    insertAtRandom(20, 2);  // Insert 20 at position 2
    insertAtRandom(30, 3);  // Insert 30 at position 3
    insertAtRandom(40, 2);  // Insert 40 at position 2

    printf("Linked List after insertions:\n");
    display();

    // Delete a node
    deleteAtRandom(3);  // Delete the node at position 3
    printf("Linked List after deletion at position 3:\n");
    display();

    // Reverse the list
    reverse();
    printf("Reversed Linked List:\n");
    display();

    return 0;
}