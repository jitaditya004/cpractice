#include <stdio.h>
#include <stdlib.h>

// Structure definition for Student
struct Student {
    int id;               // Unique ID for the student
    char *name;           // Pointer to dynamically allocated memory for the student's name
    float cgpa;           // CGPA of the student
    struct Student *next; // Pointer to the next student in the linked list
};

// Function to create a new student
struct Student* createStudent(int id) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    newStudent->id = id;          // Set the unique ID
    newStudent->name = NULL;      // Initialize name pointer
    newStudent->cgpa = 0.0;       // Initialize CGPA
    newStudent->next = NULL;      // Initialize next pointer
    return newStudent;
}

// Custom function to calculate the length of a string
size_t myStrlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Custom function to copy a string
void myStrcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// Function to accept student details
void acceptDetails(struct Student *student) {
    char buffer[100]; // Temporary buffer to store name
    printf("Enter student's name: ");
    
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Remove newline character if present
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                break;
            }
        }
        
        // Allocate memory and copy buffer to student's name
        student->name = malloc(myStrlen(buffer) + 1); // +1 for null terminator
        myStrcpy(student->name, buffer);
    }

    printf("Enter CGPA: ");
    scanf("%f", &(student->cgpa));
    getchar(); // Consume newline character after entering CGPA
}

// Function to display student details
void displayStudent(struct Student *student) {
    if (student != NULL) {
        printf("ID: %d\n", student->id);
        printf("Name: %s\n", student->name);
        printf("CGPA: %.2f\n", student->cgpa);
    } else {
        printf("Student not found.\n");
    }
}

// Function to add a student to the linked list
struct Student* addStudent(struct Student *head) {
    static int uniqueID = 1; // Static variable to generate unique IDs
    struct Student *newStudent = createStudent(uniqueID++);
    acceptDetails(newStudent);
    
    // Display the unique ID assigned to the student
    printf("Student created with ID: 23UCS%03d\n", newStudent->id);
    
    // Insert at the beginning for simplicity
    newStudent->next = head;
    return newStudent;
}

// Function to find a student by ID
struct Student* findStudent(struct Student *head, int id) {
    struct Student *current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current; // Student found
        }
        current = current->next;
    }
    return NULL; // Student not found
}

// Function to modify a student's details
void modifyStudent(struct Student *student) {
    if (student != NULL) {
        printf("Modifying details for ID: %d\n", student->id);
        acceptDetails(student);
    }
}

// Function to delete a student from the linked list
struct Student* deleteStudent(struct Student *head, int id) {
    struct Student *current = head;
    struct Student *previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with ID %d not found.\n", id);
        return head; // Student not found
    }

    // Remove the student from the list
    if (previous == NULL) {
        // Removing the head
        head = current->next;
    } else {
        previous->next = current->next; // Bypass the current node
    }

    // Free memory for the student
    free(current->name);
    free(current);
    printf("Student with ID %d deleted successfully.\n", id);
    return head;
}

// Function to free all allocated memory in the linked list
void freeList(struct Student *head) {
    struct Student *current = head;
    struct Student *next;

    while (current != NULL) {
        next = current->next;
        free(current->name); // Free name memory
        free(current); // Free student memory
        current = next;
    }
}

// Main function
int main() {
    struct Student *head = NULL; // Initialize the head of the linked list
    int choice, id;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Find Student by ID\n");
        printf("3. Modify Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after entering choice

        switch (choice) {
            case 1:
                head = addStudent(head); // Add student without needing to specify an ID
                break;

            case 2:
                printf("Enter ID to find: ");
                scanf("%d", &id);
                getchar(); // Consume newline character
                displayStudent(findStudent(head, id));
                break;

            case 3:
                printf("Enter ID to modify: ");
                scanf("%d", &id);
                getchar(); // Consume newline character
                modifyStudent(findStudent(head, id));
                break;

            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                getchar(); // Consume newline character
                head = deleteStudent(head, id);
                break;

            case 5:
                freeList(head); // Free all memory
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

