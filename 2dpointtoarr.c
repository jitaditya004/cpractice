#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate memory for a 2D array
int **allocateArray(int rows, int cols) {
    int **array = (int **)malloc(rows * sizeof(int *)); // Allocate memory for rows
    if (array == NULL) {
        printf("Memory allocation failed for rows.\n");
        exit(1);
    }
    
    // Allocate memory for columns of each row
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation failed for columns.\n");
            exit(1);
        }
    }
    return array;
}

// Function to fill the 2D array with user input
void fillArray(int **array, int rows, int cols) {
    printf("Enter elements for 4x4 array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}

// Function to display the 2D array
void displayArray(int **array, int rows, int cols) {
    printf("\n2D Array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(array + i) + j)); // Accessing using pointer arithmetic
        }
        printf("\n");
    }
}

// Function to free the allocated memory
void freeArray(int **array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]); // Free each row
    }
    free(array); // Free the array of pointers
}

int main() {
    int rows = 4, cols = 4;

    // Dynamically allocate memory for the 2D array
    int **array = allocateArray(rows, cols);

    // Fill the array with user input
    fillArray(array, rows, cols);

    // Display the 2D array
    displayArray(array, rows, cols);

    // Free the allocated memory
    freeArray(array, rows);

    return 0;
}
