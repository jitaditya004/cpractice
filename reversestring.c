#include <stdio.h>
#include <stdlib.h>

void reverseString(char str[], int length) {
    int start = 0;
    int end = length - 1;
    char temp;

    // Reverse the string
    while (start < end) {
        // Swap characters
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move towards middle
        start++;
        end--;
    }
}

int main() {
    char *str = NULL;
    size_t size = 0;
    ssize_t length;

    printf("Enter a string: ");
    length = getline(&str, &size, stdin);

    // Remove newline character from getline if present
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
        length--;
    }

    reverseString(str, length);

    printf("Reversed string: %s\n", str);

    free(str); // Free dynamically allocated memory
    return 0;
}