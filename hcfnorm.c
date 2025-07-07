#include <stdio.h>

// Function to find HCF using the iterative version of Euclid's algorithm
int hcf(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    
    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Calculate and display the HCF
    printf("HCF of %d and %d is: %d\n", num1, num2, hcf(num1, num2));
    
    return 0;
}