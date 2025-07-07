#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct Node {
    char data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, char data) {
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

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if a linked list is a palindrome
int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return 1;
    }

    // Step 1: Find the middle of the linked list using slow and fast pointers
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the linked list
    struct Node* secondHalf = reverseList(slow);
    struct Node* firstHalf = head;

    // Step 3: Compare the first half with the reversed second half
    struct Node* tempSecondHalf = secondHalf;
    int isPalindrome = 1;

    while (tempSecondHalf != NULL) {
        if (firstHalf->data != tempSecondHalf->data) {
            isPalindrome = 0;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecondHalf = tempSecondHalf->next;
    }

    // Step 4: Restore the original list structure (optional)
    reverseList(secondHalf);  // Reverse the second half again to restore the list

    return isPalindrome;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%c -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Example: Creating a linked list with characters
    insertEnd(&head, 'r');
    insertEnd(&head, 'a');
    insertEnd(&head, 'd');
    insertEnd(&head, 'a');
    insertEnd(&head, 'r');

    printf("Original list: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}