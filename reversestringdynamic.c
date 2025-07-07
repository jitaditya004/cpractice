#include <stdio.h>
#include <stdlib.h>

char* reverseString(const char* str) {
    int length = 0;

    // Find the length of the string manually
    while (str[length] != '\0') {
        length++;
    }

    // Dynamically allocate memory for the reversed string
    char* reversedStr = (char*)malloc((length + 1) * sizeof(char));

    // Check if memory allocation was successful
    if (reversedStr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Reverse the string
    for (int i = 0; i < length; ++i) {
        reversedStr[i] = str[length - i - 1];
    }

    // Null-terminate the reversed string
    reversedStr[length] = '\0';

    return reversedStr;
}

int main() {
    char str[100];

    // Input the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character added by fgets
    str[strcspn(str, "\n")] = 0;

    // Reverse the string
    char* reversed = reverseString(str);

    // Output the reversed string
    printf("Reversed: %s\n", reversed);

    // Free the dynamically allocated memory
    free(reversed);

    return 0;
}