#include <stdio.h>
#include <stdlib.h>

// Function to count the number of words in a sentence
int countWords(char *sentence) {
    int count = 0;
    int inWord = 0;

    // Loop through each character in the sentence
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] != ' ' && sentence[i] != '\n' && !inWord) {
            // Start of a new word
            inWord = 1;
            count++;
        } else if (sentence[i] == ' ' || sentence[i] == '\n') {
            // End of the current word
            inWord = 0;
        }
    }

    return count;
}

int main() {
    int numSentences = 0;
    
    printf("Enter the number of sentences: ");
    scanf("%d", &numSentences);
    getchar(); // Consume the newline after entering the number

    // Dynamic allocation for sentences
    char **sentences = (char **)malloc(numSentences * sizeof(char *));
    
    for (int i = 0; i < numSentences; i++) {
        // Allocate memory for each sentence (limiting each sentence length to 1000 for simplicity)
        sentences[i] = (char *)malloc(1000 * sizeof(char));

        // Input each sentence
        printf("Enter sentence %d: ", i + 1);
        fgets(sentences[i], 1000, stdin);

        // Count words in the current sentence and output
        int wordCount = countWords(sentences[i]);
        printf("Sentence %d has %d words.\n", i + 1, wordCount);
    }

    // Free allocated memory
    for (int i = 0; i < numSentences; i++) {
        free(sentences[i]);
    }
    free(sentences);

    return 0;
}
