#include <stdio.h>
#include <stdlib.h>

// Custom function to check if a character is a vowel
int isVowel(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch += 32;  // Convert uppercase to lowercase
    }
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Custom function to check if a character is a space, tab, or newline (i.e., word separator)
int isSpace(char ch) {
    return (ch == ' ' || ch == '\n' || ch == '\t');
}

int main() {
    char *str = NULL;
    size_t len = 0;
    ssize_t read;

    // Input the string using getline
    printf("Enter a string: ");
    read = getline(&str, &len, stdin);

    if (read == -1) {
        printf("Error reading input\n");
        free(str);
        return 1;
    }

    int vowelCount = 0, wordCount = 0, sentenceCount = 0;
    int inWord = 0;  // Flag to track whether we are inside a word

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // Count vowels using custom function
        if (isVowel(ch)) {
            vowelCount++;
        }

        // Count sentences (period, exclamation mark, or question mark)
        if (ch == '.' || ch == '!' || ch == '?') {
            sentenceCount++;
        }

        // Count words: words are separated by spaces, tabs, or newline
        if (isSpace(ch)) {
            if (inWord) {
                wordCount++;
                inWord = 0;  // Exiting a word
            }
        } else if (!inWord) {
            inWord = 1;  // Starting a new word
        }
    }

    // If the string ends with a word (no space or newline), count the last word
    if (inWord) {
        wordCount++;
    }

    // Print the results
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of sentences: %d\n", sentenceCount);

    // Free dynamically allocated memory
    free(str);

    return 0;
}