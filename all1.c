#include <stdio.h>
#include <stdlib.h>

// Function to allocate a 2D array as a single block of memory
int* allocate2DArray(int m, int n) {
    // Allocate a single block of memory for m*n elements
    int* array = (int*)malloc(m * n * sizeof(int));

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    return array;
}

// Function to initialize the 2D array with sample values
void initialize2DArray(int* array, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            array[i * n + j] = i * n + j;  // Sample initialization
        }
    }
}

// Function to print the 2D array
void print2DArray(int* array, int m, int n) {
    printf("2D Array:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", array[i * n + j]);
        }
        printf("\n");
    }
}

// Function to free the allocated memory for the 2D array
void free2DArray(int* array) {
    free(array);  // Free the single block of memory
}

int main() {
    int m, n;
    
    // Input the dimensions
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    
    printf("Enter the size of each row (n): ");
    scanf("%d", &n);

    // Allocate the 2D array
    int* array = allocate2DArray(m, n);

    // Initialize the 2D array
    initialize2DArray(array, m, n);

    // Print the 2D array
    print2DArray(array, m, n);

    // Free the dynamically allocated memory
    free2DArray(array);

    return 0;
}