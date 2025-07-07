#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold person and movie data
struct Person {
    char *name;       // Dynamically allocated name of the person
    char *movie;      // Dynamically allocated name of the movie
    float amountPaid; // Amount paid for the movie
};
struct  Person persons;

// Function prototypes
void addPerson(struct Person **persons, int *count);
void deletePerson(struct Person **persons, int *count);
void displayPersons(struct Person *persons, int count);
void freePersons(struct Person *persons, int count);

int main() {
    struct Person *persons = NULL; // Pointer to hold dynamically allocated persons
    int count = 0; // Current number of persons
    int choice;

    do {
        printf("\n--- Movie Ticket Management System ---\n");
        printf("1. Add Person\n");
        printf("2. Delete Person\n");
        printf("3. Display Persons\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after entering choice

        switch (choice) {
            case 1:
                addPerson(&persons, &count); // Add person and manage memory dynamically
                break;

            case 2:
                deletePerson(&persons, &count); // Delete a person
                break;

            case 3:
                displayPersons(persons, count); // Display all persons
                break;

            case 4:
                freePersons(persons, count); // Free memory before exiting
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to add a person to the dynamic array
void addPerson(struct Person **persons, int *count) {
    // Allocate memory for a new person
    *persons = realloc(*persons, (*count + 1) * sizeof(struct Person));
    if (*persons == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Allocate memory for name and movie using malloc
    (*persons)[*count].name = malloc(50 * sizeof(char));
    (*persons)[*count].movie = malloc(100 * sizeof(char));

    if ((*persons)[*count].name == NULL || (*persons)[*count].movie == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Input person's name
    printf("Enter person's name: ");
    fgets((*persons)[*count].name, 50, stdin);
    (*persons)[*count].name[strcspn((*persons)[*count].name, "\n")] = '\0'; // Remove newline character

    // Input movie name
    printf("Enter movie name: ");
    fgets((*persons)[*count].movie, 100, stdin);
    (*persons)[*count].movie[strcspn((*persons)[*count].movie, "\n")] = '\0'; // Remove newline character

    // Input amount paid
    printf("Enter amount paid: ");
    scanf("%f", &(*persons)[*count].amountPaid);
    getchar(); // Consume newline character

    (*count)++; // Increment the count of persons
    printf("Person added successfully.\n");
}

// Function to delete a person from the dynamic array
void deletePerson(struct Person **persons, int *count) {
    if (*count == 0) {
        printf("No persons to delete.\n");
        return;
    }

    char name[50];
    printf("Enter person's name to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < *count; i++) {
        if (strcmp((*persons)[i].name, name) == 0) {
            // Free dynamically allocated memory
            free((*persons)[i].name);
            free((*persons)[i].movie);

            // Shift remaining persons left
            for (int j = i; j < *count - 1; j++) {
                (*persons)[j] = (*persons)[j + 1];
            }

            (*count)--; // Decrement the count of persons
            *persons = realloc(*persons, (*count) * sizeof(struct Person)); // Resize the array
            printf("Person '%s' deleted successfully.\n", name);
            return;
        }
    }
    printf("Person with name '%s' not found.\n", name);
}

// Function to display all persons
void displayPersons(struct Person *persons, int count) {
    if (count == 0) {
        printf("No persons to display.\n");
        return;
    }

    printf("\n--- List of Persons ---\n");
    for (int i = 0; i < count; i++) {
        printf("Person %d: Name: %s, Movie: %s, Amount Paid: %.2f\n", i + 1, persons[i].name, persons[i].movie, persons[i].amountPaid);
    }
}

// Function to free all allocated memory for persons
void freePersons(struct Person *persons, int count) {
    for (int i = 0; i < count; i++) {
        free(persons[i].name);
        free(persons[i].movie);
    }
    free(persons); // Free the main array
}