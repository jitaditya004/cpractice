#include <stdio.h>
#include <stdlib.h>

// Define structure for the tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Global root node
struct Node* root = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
struct Node* insertNode(struct Node* node, int data) {
    // If the tree is empty, assign a new node to root
    if (node == NULL) {
        return createNode(data);
    }

    // Recursively insert data
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }

    return node;
}

// Function to search for a node in the binary search tree
struct Node* searchNode(struct Node* node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    }

    // Recursively search in left or right subtree
    if (data < node->data) {
        return searchNode(node->left, data);
    } else {
        return searchNode(node->right, data);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Node with value %d inserted.\n", value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* result = searchNode(root, value);
                if (result != NULL) {
                    printf("Node with value %d found.\n", value);
                } else {
                    printf("Node with value %d not found.\n", value);
                }
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}