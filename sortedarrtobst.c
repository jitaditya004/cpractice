#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Global root pointer
struct TreeNode* root = NULL;

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to convert sorted array to BST
struct TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    // Base case: if start is greater than end, return NULL
    if (start > end)
        return NULL;

    // Find the middle element
    int mid = (start + end) / 2;

    // Create a new node with the middle element
    struct TreeNode* node = createNode(arr[mid]);

    // Recursively construct the left subtree
    node->left = sortedArrayToBST(arr, start, mid - 1);

    // Recursively construct the right subtree
    node->right = sortedArrayToBST(arr, mid + 1, end);

    return node;
}

// In-order traversal to print the BST
void inOrder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {
    int n, i;

    // Taking the size of the array as input
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));

    // Taking the array elements as input
    printf("Enter the elements of the sorted array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Create the BST
    root = sortedArrayToBST(arr, 0, n - 1);

    // Print in-order traversal of the BST
    printf("In-order traversal of the BST: ");
    inOrder(root);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
