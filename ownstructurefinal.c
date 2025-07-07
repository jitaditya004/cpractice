#include <stdio.h>
#include <stdlib.h>

// Structure for a person node
struct Person {
    char *name;        // Dynamically allocated name of the person
    char *movie;       // Dynamically allocated name of the movie
    struct Person *next; // Pointer to the next person in the list
};

// Function prototypes
struct Person* createPerson();
void displayPersons(struct Person *head);
void modifyPerson(struct Person *head);
void freeList(struct Person *head);

// Helper function to remove newline characters
void removeNewline(char *str);

// Main function
int main() {
    struct Person *head = NULL, *temp = NULL;
    int choice;

    do {
        printf("\n--- Person and Movie Management System ---\n");
        printf("1. Add Person\n");
        printf("2. Modify Person\n");
        printf("3. Display Persons\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline after entering the choice

        switch (choice) {
            case 1: {
                struct Person *newPerson = createPerson();
                if (head == NULL) {
                    head = newPerson;
                } else {
                    temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newPerson;
                }
                break;
            }

            case 2:
                modifyPerson(head);
                break;

            case 3:
                displayPersons(head);
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

// Function to create a new person and get input using getline
struct Person* createPerson() {
    struct Person *newPerson = (struct Person *)malloc(sizeof(struct Person));
    if (newPerson == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize next pointer to NULL
    newPerson->next = NULL;

    // Input name using getline
    size_t len = 0;
    newPerson->name = NULL;
    printf("Enter person's name: ");
    getline(&newPerson->name, &len, stdin);
    removeNewline(newPerson->name);

    // Input movie using getline
    len = 0;
    newPerson->movie = NULL;
    printf("Enter movie name: ");
    getline(&newPerson->movie, &len, stdin);
    removeNewline(newPerson->movie);

    return newPerson;
}

// Function to display all persons and their movie names
void displayPersons(struct Person *head) {
    if (head == NULL) {
        printf("No persons to display.\n");
        return;
    }

    printf("\n--- List of Persons and Movies ---\n");
    struct Person *temp = head;
    int index = 1;
    while (temp != NULL) {
        printf("Person %d: Name: %s, Movie: %s\n", index, temp->name, temp->movie);
        temp = temp->next;
        index++;
    }
}

// Function to modify an existing person's details
/*void modifyPerson(struct Person *head) {
    if (head == NULL) {
        printf("No persons to modify.\n");
        return;
    }

    char *name = NULL;
    size_t len = 0;

    // Input name of person to modify
    printf("Enter the name of the person to modify: ");
    getline(&name, &len, stdin);
    removeNewline(name);

    struct Person *temp = head;
    while (temp != NULL) {
        // Check if the name matches
        int i = 0;
        while (temp->name[i] != '\0' && name[i] != '\0' && temp->name[i] == name[i]) {
            i++;
        }
        if (temp->name[i] == '\0' && name[i] == '\0') { // Name matches
            printf("Modifying details for %s...\n", temp->name);

            // Modify movie name
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
}*/
// Function to modify an existing person's details
void modifyPerson(struct Person *head) {
    if (head == NULL) {
        printf("No persons to modify.\n");
        return;
    }

    char *name = NULL;
    size_t len = 0;

    // Input the name of the person to modify
    printf("Enter the name of the person to modify: ");
    getline(&name, &len, stdin);
    removeNewline(name);

    struct Person *temp = head;
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
void freeList(struct Person *head) {
    struct Person *temp = head;
    while (temp != NULL) {
        struct Person *next = temp->next;
        free(temp->name);
        free(temp->movie);
        free(temp);
        temp = next;
    }
}