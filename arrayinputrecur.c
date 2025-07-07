#include <stdio.h>
#include <stdlib.h>

// Recursive function to input elements into the array
void inputArray(int* array, int index, int n) {
    // Base case: stop when the index reaches the size of the array
    if (index == n) {
        return;
    }
    
    // Input the current element
    printf("Enter element %d: ", index + 1);
    scanf("%d", &array[index]);
    
    // Recursive call for the next element
    inputArray(array, index + 1, n);
}

// Recursive function to display elements of the array
void displayArray(int* array, int index, int n) {
    // Base case: stop when the index reaches the size of the array
    if (index == n) {
        return;
    }
    
    // Display the current element
    printf("%d ", array[index]);
    
    // Recursive call for the next element
    displayArray(array, index + 1, n);
}

int main() {
    int n;
    
    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the array
    int* array = (int*)malloc(n * sizeof(int));
    
    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input the array elements using recursion
    inputArray(array, 0, n);
    
    // Display the array elements using recursion
    printf("Array elements are: ");
    displayArray(array, 0, n);
    printf("\n");
    
    // Free the dynamically allocated memory
    free(array);
    
    return 0;
}