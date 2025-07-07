#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;  // Global head pointer

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert at the front of the list
void insertFront(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head->prev = head;
    } else {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = head->prev = newNode;
        head = newNode;
    }
}

// Insert at the end of the list
void insertEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head->prev = head;
    } else {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = head->prev = newNode;
    }
}

// Delete from the front of the list
void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        struct Node *last = head->prev;
        head = head->next;
        head->prev = last;
        last->next = head;
    }
    free(temp);
}

// Delete from the end of the list
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *last = head->prev;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *secondLast = last->prev;
        secondLast->next = head;
        head->prev = secondLast;
        free(last);
    }
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertFront(5);
    display();  // Output: 5 10 20

    deleteFront();
    display();  // Output: 10 20

    deleteEnd();
    display();  // Output: 10

    return 0;
}