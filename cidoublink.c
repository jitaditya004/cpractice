#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Initially, the next points to itself
    newNode->prev = newNode; // Initially, the prev points to itself
    return newNode;
}

// Function to insert a node at any position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        // If the list is empty, the new node becomes the head
        *head = newNode;
    } else if (position == 0) {
        // Insert at the head (position 0)
        struct Node* tail = (*head)->prev; // Get the current tail
        newNode->next = *head;             // New node points to the head
        newNode->prev = tail;               // New node's prev points to the tail
        tail->next = newNode;               // Old tail points to new node
        (*head)->prev = newNode;            // Head's prev points to new node
        *head = newNode;                    // Update head
    } else {
        struct Node* current = *head;
        int count = 0;
        
        // Traverse to the desired position
        while (count < position - 1 && current->next != *head) {
            current = current->next;
            count++;
        }
        
        newNode->next = current->next; // New node points to the next node
        newNode->prev = current;        // New node's prev points to current
        current->next->prev = newNode;  // Next node's prev points to new node
        current->next = newNode;        // Current node points to new node
    }
}

// Function to delete a node by value
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* toDelete = NULL;

    // Search for the node with the given data
    do {
        if (current->data == data) {
            toDelete = current;
            break;
        }
        current = current->next;
    } while (current != *head);

    if (toDelete != NULL) {
        // Node found; update links
        if (toDelete == *head) {
            if (toDelete->next == *head) {
                // Only one node in the list
                free(toDelete);
                *head = NULL; // List becomes empty
                return;
            } else {
                // More than one node; update head
                *head = toDelete->next;
            }
        }
        
        // Adjust pointers for previous and next nodes
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        free(toDelete); // Free the memory of the deleted node
    } else {
        printf("Node with value %d not found.\n", data);
    }
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at position\n");
        printf("2. Delete by value\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at (0 for head): ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                // Free the linked list memory before exit
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
