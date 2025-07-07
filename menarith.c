#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void add(float *a, float *b, float *result);
void subtract(float *a, float *b, float *result);
void multiply(float *a, float *b, float *result);
void divide(float *a, float *b, float *result);

int main() {
    int choice;
    float *num1, *num2, result;

    // Dynamically allocate memory for num1 and num2
    num1 = (float *)malloc(sizeof(float));
    num2 = (float *)malloc(sizeof(float));

    if (num1 == NULL || num2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        printf("Enter first number: ");
        scanf("%f", num1);  // Corrected: pass num1, not &num1
        printf("Enter second number: ");
        scanf("%f", num2);  // Corrected: pass num2, not &num2

        switch (choice) {
            case 1:
                add(num1, num2, &result);
                printf("Result: %.2f\n", result);
                break;
            case 2:
                subtract(num1, num2, &result);
                printf("Result: %.2f\n", result);
                break;
            case 3:
                multiply(num1, num2, &result);
                printf("Result: %.2f\n", result);
                break;
            case 4:
                if (*num2 != 0) {
                    divide(num1, num2, &result);
                    printf("Result: %.2f\n", result);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    // Free allocated memory
    free(num1);
    free(num2);

    return 0;
}

// Function to add two numbers
void add(float *a, float *b, float *result) {
    *result = *a + *b;
}

// Function to subtract two numbers
void subtract(float *a, float *b, float *result) {
    *result = *a - *b;
}

// Function to multiply two numbers
void multiply(float *a, float *b, float *result) {
    *result = *a * *b;
}

// Function to divide two numbers
void divide(float *a, float *b, float *result) {
    *result = *a / *b;
}