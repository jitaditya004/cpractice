#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory using malloc
int* allocate_with_malloc(int size) {
    int *ptr = (int *)malloc(size * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation with malloc failed!\n");
        exit(1);  // Exit the program if allocation fails
    }
    return ptr;
}

// Function to allocate memory using calloc
int* allocate_with_calloc(int size) {
    int *ptr = (int *)calloc(size, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation with calloc failed!\n");
        exit(1);  // Exit the program if allocation fails
    }
    return ptr;
}

// Function to print array elements
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

int main() {
    int size = 5;

    // Using malloc
    int *arr_malloc = allocate_with_malloc(size);
    for (int i = 0; i < size; i++) {
        arr_malloc[i] = i + 1;  // Initialize values
    }
    printf("Array allocated with malloc:\n");
    print_array(arr_malloc, size);

    // Free the allocated memory
    free(arr_malloc);
    printf("Memory allocated with malloc has been freed.\n");

    // Using calloc
    int *arr_calloc = allocate_with_calloc(size);
    printf("Array allocated with calloc:\n");
    print_array(arr_calloc, size);

    // Free the allocated memory
    free(arr_calloc);
    printf("Memory allocated with calloc has been freed.\n");

    return 0;
}