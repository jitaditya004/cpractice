#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num, int divisor) {
    if (num <= 1) return false;
    if (divisor == 1) return true;
    if (num % divisor == 0) return false;
    return isPrime(num, divisor - 1);
}

// Recursive function to count prime numbers in the array
int countPrimes(int* array, int index, int n) {
    // Base case: stop when the index reaches the size of the array
    if (index == n) {
        return 0;
    }

    // Check if the current element is prime
    int primeCount = isPrime(array[index], array[index] / 2) ? 1 : 0;

    // Add the current count and move to the next element recursively
    return primeCount + countPrimes(array, index + 1, n);
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
    
    // Input the array elements
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    
    // Count the prime numbers in the array using recursion
    int primeCount = countPrimes(array, 0, n);
    
    // Display the result
    printf("Number of prime numbers in the array: %d\n", primeCount);
    
    // Free the dynamically allocated memory
    free(array);
    
    return 0;
}