#include <stdio.h>

// User-defined function to convert decimal to binary
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }
    
    int binary[32]; // Array to store binary digits
    int index = 0;

    // Convert decimal to binary
    while (decimal > 0) {
        binary[index] = decimal % 2; // Store remainder (binary digit)
        decimal = decimal / 2;        // Update decimal number
        index++;
    }

    // Print binary digits in reverse order
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int decimal;

    // Input decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Call the function to convert and display binary
    decimalToBinary(decimal);

    return 0;
}