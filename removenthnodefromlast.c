#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
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

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove the nth node from the end in one pass
void removeNthFromEnd(struct Node** head, int n) {
    struct Node* fast = *head;
    struct Node* slow = *head;
    struct Node* prev = NULL;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            printf("The list has fewer than %d nodes.\n", n);
            return;
        }
        fast = fast->next;
    }

    // If fast is NULL, it means we need to remove the head node
    if (fast == NULL) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Move both slow and fast pointers until fast reaches the end
    while (fast != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // Now, slow is the nth node from the end, remove it
    prev->next = slow->next;
    free(slow);
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Example: Creating a linked list with integers
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    printf("Original list: ");
    printList(head);

    int n = 2; // Remove the 2nd node from the end
    removeNthFromEnd(&head, n);

    printf("List after removing the %d-th node from the end: ", n);
    printList(head);

    return 0;
}