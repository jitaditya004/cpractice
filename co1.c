#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For memcpy (optional)

int main() {
    int original_size ;
    scanf("%d",&original_size);
    for (int i = 0; i < original_size; i++) {
        scanf("%d"
    }
    int *original_array = (int *)malloc(original_size * sizeof(int));
    if (original_array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the original array
    for (int i = 0; i < original_size; i++) {
        original_array[i] = i + 1;
    }

    // Print original array
    printf("Original array: ");
    for (int i = 0; i < original_size; i++) {
        printf("%d ", original_array[i]);
    }
    printf("\n");

    // Allocate memory for the new array
    int *copied_array = (int *)malloc(original_size * sizeof(int));
    if (copied_array == NULL) {
        printf("Memory allocation failed!\n");
        free(original_array); // Free the original array before exiting
        return 1;
    }

    // Copy the elements from the original array to the new array
    for (int i = 0; i < original_size; i++) {
        copied_array[i] = original_array[i];
    }

    // Print copied array
    printf("Copied array: ");
    for (int i = 0; i < original_size; i++) {
        printf("%d ", copied_array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(original_array);
    free(copied_array);

    return 0;
}