#include <stdio.h>
#include <stdlib.h>

// Function to add a new value and calculate the moving average
double addValueAndCalculateAverage(double *data, int *size, int capacity, double newValue, double *sum) {
    if (*size < capacity) {
        // If there's space in the array, just add the new value
        data[*size] = newValue;
        *sum += newValue;
        (*size)++;
    } else {
        // If the array is full, subtract the oldest value
        *sum -= data[0];

        // Shift elements to the left
        for (int i = 1; i < capacity; i++) {
            data[i - 1] = data[i];
        }

        // Add the new value at the end
        data[capacity - 1] = newValue;
        *sum += newValue;
    }

    // Calculate and return the moving average
    return *sum / (*size < capacity ? *size : capacity);
}

int main() {
    int n; // Size of the moving window
    printf("Enter the size of the moving window: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the moving window
    double *data = (double *)malloc(n * sizeof(double));
    int size = 0;      // Current size of the array (number of elements)
    double sum = 0.0;  // Sum of the elements in the array

    double value;
    printf("Enter numbers to calculate the moving average (type -1 to exit):\n");

    while (1) {
        printf("Enter a number: ");
        scanf("%lf", &value);
        if (value == -1) {
            break;
        }

        // Call the function to add the value and calculate the moving average
        double average = addValueAndCalculateAverage(data, &size, n, value, &sum);
        printf("Current Moving Average: %.2f\n", average);
    }

    // Free the dynamically allocated memory
    free(data);
    
    return 0;
}
