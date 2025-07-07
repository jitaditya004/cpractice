#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode;  // Circular linking
    return newNode;
}

// Insert at the beginning
void insertBegin(int data) {
    struct Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
    } else {
        struct Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = head->prev = newNode;
        head = newNode;
    }
}

// Insert at the end
void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
    } else {
        struct Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
}

// Insert at a specific position
void insertAtPos(int data, int pos) {
    struct Node* newNode = createNode(data);
    if (pos == 1) {
        insertBegin(data);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range\n");
            return;
        }
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from the beginning
void deleteBegin() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    struct Node* last = head->prev;
    if (head->next == head) {  // Only one node
        head = NULL;
    } else {
        last->next = head->next;
        head->next->prev = last;
        head = head->next;
    }
    free(temp);
}

// Delete from the end
void deleteEnd() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node* last = head->prev;
    if (head->next == head) {  // Only one node
        head = NULL;
    } else {
        last->prev->next = head;
        head->prev = last->prev;
    }
    free(last);
}

// Delete at a specific position
void deleteAtPos(int pos) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        deleteBegin();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range\n");
            return;
        }
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// Search by position
void searchByPosition(int pos) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range\n");
            return;
        }
    }
    printf("Node at position %d has data: %d\n", pos, temp->data);
}

// Search by value
void searchByValue(int value) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Value %d not found in the list\n", value);
}

// Traverse from the beginning
void traverseBegin() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Traverse in reverse from the end
void traverseEnd() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head->prev;
    do {
        printf("%d <- ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(head)\n");
}

int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertBegin(0);
    insertAtPos(5, 3);
    traverseBegin();

    deleteEnd();
    deleteBegin();
    deleteAtPos(2);
    traverseBegin();

    searchByPosition(2);
    searchByValue(5);

    traverseEnd();

    return 0;
}
