#include <stdio.h>

void findLargestAndSecondLargest(int arr[], int n) {
    if (n < 2) {
        printf("Array must contain at least two elements.\n");
        return;
    }

    int largest = arr[0];
    int secondLargest = -1; // Assuming all numbers are non-negative

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == -1) {
        printf("There is no distinct second largest element.\n");
    } else {
        printf("Largest element: %d\n", largest);
        printf("Second largest element: %d\n", secondLargest);
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must contain at least two elements.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findLargestAndSecondLargest(arr, n);

    return 0;
}