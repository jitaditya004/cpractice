#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is composite
int isComposite(int num) {
    if (num <= 1) {
        return 0;  // Numbers <= 1 are not composite
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 1;  // If divisible by i, it’s composite
        }
    }
    return 0;  // No divisors found, it's prime
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get array elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    // Calculate the sum of composite numbers
    int compositeSum = 0;
    for (int *ptr = arr; ptr < arr + n; ptr++) {
        if (isComposite(*ptr)) {
            compositeSum += *ptr;
        }
    }

    printf("Sum of composite numbers: %d\n", compositeSum);

    // Free the allocated memory
    free(arr);
    return 0;
}
