#include <stdio.h>
#include <stdlib.h>

char* reverseString(const char* str, int length) {
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
    int length = 0;

    // Read input character by character
    printf("Enter a string: ");
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF && length < 100 - 1) {
        str[length++] = ch;
    }
    str[length] = '\0';  // Null-terminate the original string

    // Reverse the string
    char* reversed = reverseString(str, length);

    // Output the reversed string
    printf("Reversed: %s\n", reversed);

    // Free the dynamically allocated memory
    free(reversed);

    return 0;
}