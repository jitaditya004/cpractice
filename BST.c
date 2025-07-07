#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Global root of the BST
struct Node* root = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node in the BST
void insert(int data) {
    struct Node* newNode = createNode(data);
    
    if (root == NULL) {
        root = newNode;
        return;
    }

    struct Node* current = root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Find the minimum node in the right subtree
struct Node* findMin(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Delete a node from the BST
struct Node* deleteNode(struct Node* node, int data) {
    if (node == NULL) {
        return NULL;
    }

    if (data < node->data) {
        node->left = deleteNode(node->left, data);
    } else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    } else {
        // Node to be deleted found
        if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(node->right);

        // Copy the inorder successor's data to this node
        node->data = temp->data;

        // Delete the inorder successor
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

// In-order traversal (used to display the tree)
void inorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }

    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

int main() {
    // Insertion in the BST
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    printf("In-order traversal before deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Deleting node with value 20
    root = deleteNode(root, 20);
    printf("In-order traversal after deleting 20: ");
    inorderTraversal(root);
    printf("\n");

    // Deleting node with value 30
    root = deleteNode(root, 30);
    printf("In-order traversal after deleting 30: ");
    inorderTraversal(root);
    printf("\n");

    // Deleting node with value 50
    root = deleteNode(root, 50);
    printf("In-order traversal after deleting 50: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}