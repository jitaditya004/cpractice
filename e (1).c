#include <stdio.h>
#include <stdlib.h>

// Structure for a movies node
struct Movies {
    char *name;        // Dynamically allocated name of the person
    char *movie;       // Dynamically allocated name of the movie
    struct Movies *next; // Pointer to the next movie in the list
};

// Function prototypes
struct Movies* createMovie();
void displayMovies(struct Movies *head);
void modifyMovie(struct Movies *head);
void freeList(struct Movies *head);

// Helper function to remove newline characters
void removeNewline(char *str);

// Main function
int main() {
    struct Movies *head = NULL, *temp = NULL;
    int choice;

    do {
        printf("\n--- Movie Management System ---\n");
        printf("1. Add Movie\n");
        printf("2. Modify Movie\n");
        printf("3. Display Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline after entering the choice

        switch (choice) {
            case 1: {
                struct Movies *newMovie = createMovie();
                if (head == NULL) {
                    head = newMovie;
                } else {
                    temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newMovie;
                }
                break;
            }

            case 2:
                modifyMovie(head);
                break;

            case 3:
                displayMovies(head);
                break;

            case 4:
                freeList(head);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to create a new movie and get input using getline
struct Movies* createMovie() {
    struct Movies *newMovie = (struct Movies *)malloc(sizeof(struct Movies));
    if (newMovie == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize next pointer to NULL
    newMovie->next = NULL;

    // Input name using getline
    size_t len = 0;
    newMovie->name = NULL;
    printf("Enter person's name: ");
    getline(&newMovie->name, &len, stdin);
    removeNewline(newMovie->name);

    // Input movie using getline
    len = 0;
    newMovie->movie = NULL;
    printf("Enter movie name: ");
    getline(&newMovie->movie, &len, stdin);
    removeNewline(newMovie->movie);

    return newMovie;
}

// Function to display all movies and their associated names
void displayMovies(struct Movies *head) {
    if (head == NULL) {
        printf("No movies to display.\n");
        return;
    }

    printf("\n--- List of Movies ---\n");
    struct Movies *temp = head;
    int index = 1;
    while (temp != NULL) {
        printf("Person %d:- Name: %s, Movie: %s\n", index, temp->name, temp->movie);
        temp = temp->next;
        index++;
    }
}

// Function to modify an existing movie's details
void modifyMovie(struct Movies *head) {
    if (head == NULL) {
        printf("No movies to modify.\n");
        return;
    }

    char *name = NULL;
    size_t len = 0;

    // Input the name of the person associated with the movie to modify
    printf("Enter the name of the person to modify: ");
    getline(&name, &len, stdin);
    removeNewline(name);

    struct Movies *temp = head;
    while (temp != NULL) {
        // Check if the name matches
        int i = 0;
        while (temp->name[i] != '\0' && name[i] != '\0' && temp->name[i] == name[i]) {
            i++;
        }
        if (temp->name[i] == '\0' && name[i] == '\0') { // Name matches
            printf("Modifying details for %s...\n", temp->name);

            // Modify the name
            free(temp->name); // Free the old name
            len = 0;
            temp->name = NULL;
            printf("Enter new person's name: ");
            getline(&temp->name, &len, stdin);
            removeNewline(temp->name);

            // Modify the movie name
            free(temp->movie); // Free the old movie name
            len = 0;
            temp->movie = NULL;
            printf("Enter new movie name: ");
            getline(&temp->movie, &len, stdin);
            removeNewline(temp->movie);

            printf("Details updated successfully.\n");
            free(name); // Free the temporary input buffer
            return;
        }
        temp = temp->next;
    }

    printf("Person with name '%s' not found.\n", name);
    free(name); // Free the temporary input buffer
}

// Helper function to remove the newline character from input strings
void removeNewline(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

// Function to free all allocated memory for the list
void freeList(struct Movies *head) {
    struct Movies *temp = head;
    while (temp != NULL) {
        struct Movies *next = temp->next;
        free(temp->name);
        free(temp->movie);
        free(temp);
        temp = next;
    }
}