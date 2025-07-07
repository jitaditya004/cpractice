#include <stdio.h>

// Recursive function to find HCF using Euclid's algorithm
int hcf(int a, int b) {
    if (b == 0)
        return a;
    return hcf(b, a % b);
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