#include <stdio.h>
#include <stdlib.h>

void largest(int *large, int *seclarge, int arr[], int size) {
    if (size < 2) {
        printf("Array should have at least two elements.\n");
        *large = *seclarge = -1;
        return;
    }

    // Initialize large and seclarge with the first two elements
    if (arr[0] > arr[1]) {
        *large = arr[0];
        *seclarge = arr[1];
    } else {
        *large = arr[1];
        *seclarge = arr[0];
    }

    // Traverse the rest of the array
    for (int i = 2; i < size; i++) {
        if (arr[i] > *large) {
            *seclarge = *large;
            *large = arr[i];
        } else if (arr[i] > *seclarge && arr[i] != *large) {
            *seclarge = arr[i];
        }
    }

    // If no unique second largest, set seclarge to -1
    if (*seclarge == *large) {
        *seclarge = -1;
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void acc(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int l = 0, s = 0, size;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    int* arr = (int *)calloc(size, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    acc(arr, size);
    printf("Array elements: ");
    print(arr, size);

    largest(&l, &s, arr, size);
    if (s == -1) {
        printf("\nNo second largest element.\n");
    } else {
        printf("\nLargest element: %d\nSecond largest element: %d\n", l, s);
    }

    free(arr); // Free allocated memory
    return 0;
}
