#include <stdio.h>

// Function to reverse the first k characters of a string
void reverseKChars(char *str, int k) {
    int i = 0;
    int j = k - 1;

    // Reverse first k characters
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char str[100]; // Buffer for the input string
    int k;
    int length = 0;

    // Input string using fgets
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Calculate the length of the string manually (until we encounter '\0' or '\n')
    while (str[length] != '\n' && str[length] != '\0') {
        length++;
    }

    // Replace the newline character if present
    if (str[length] == '\n') {
        str[length] = '\0';
    }

    // Input the value of k
    printf("Enter the number of characters to reverse: ");
    scanf("%d", &k);

    // Make sure k does not exceed string length
    if (k > length) {
        k = length;
    }

    // Reverse first k characters
    reverseKChars(str, k);

    // Output the modified string
    printf("Modified string: %s\n", str);

    return 0;
}
