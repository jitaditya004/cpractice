#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the subtree rooted at the node with the given value
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Base case: root is null or the value is found
    if (root == NULL || root->data == val) {
        return root;
    }

    // If the value is less than the current node's value, search in the left subtree
    if (val < root->data) {
        return searchBST(root->left, val);
    }
    // If the value is greater than the current node's value, search in the right subtree
    else {
        return searchBST(root->right, val);
    }
}

// Function to print the in-order traversal of the tree (for testing)
void inOrder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Example of creating a simple BST and searching for a value
int main() {
    // Creating a simple BST
   /* struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
*/
    int val;
    printf("Enter the value to search for: ");
    scanf("%d", &val);

    struct TreeNode* result = searchBST(root, val);
    
    if (result != NULL) {
        printf("Subtree rooted at node with value %d: ", result->data);
        inOrder(result); // Print the subtree
        printf("\n");
    } else {
        printf("Value %d not found in the BST.\n", val);
    }

    // Free memory (not shown here for simplicity)
    return 0;
}
