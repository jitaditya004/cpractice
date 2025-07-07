#include <stdio.h>
#include <stdlib.h>

// Structure definition for Student
struct Student {
    char *name;    // Pointer to dynamically allocated memory for the student's name
    int *marks;    // Pointer to dynamically allocated array of marks
    int num_marks; // Number of marks
};

// Function to create a new student
struct Student* createStudent() {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    newStudent->name = NULL;   // Initialize name pointer
    newStudent->marks = NULL;   // Initialize marks pointer
    newStudent->num_marks = 0;  // Initialize number of marks
    return newStudent;
}

// Function to accept student details
void acceptDetails(struct Student *student) {
    size_t len = 0;

    // Dynamically allocate memory and accept the student's name using getline
    printf("Enter student's name: ");
    getline(&(student->name), &len, stdin);  // Dynamically allocates memory for the name

    // Manually remove the newline character from the name if it exists
    for (int i = 0; student->name[i] != '\0'; i++) {
        if (student->name[i] == '\n') {
            student->name[i] = '\0'; // Replace newline with null terminator
            break; // Exit the loop once we find and replace the newline
        }
    }

    printf("Enter number of marks: ");
    scanf("%d", &(student->num_marks));
    getchar(); // To consume the newline character after entering num_marks

    // Dynamically allocate memory for marks based on the number of marks
    student->marks = (int *)malloc(student->num_marks * sizeof(int));

    // Accept the marks
    printf("Enter %d marks:\n", student->num_marks);
    for (int i = 0; i < student->num_marks; i++) {
        printf("Mark %d: ", i + 1);
        scanf("%d", &(student->marks[i]));
    }
    getchar(); // To consume the newline character after entering marks
}

// Function to display the student details
void displayDetails(struct Student *student) {
    printf("%-20s", student->name);  // Print the name with a fixed width
    for (int j = 0; j < student->num_marks; j++) {
        printf("%-8d", student->marks[j]); // Print each mark with a fixed width
    }
    printf("\n");
}

// Function to free the allocated memory for a student
void freeStudent(struct Student *student) {
    free(student->name);
    free(student->marks);
    free(student);
}

int main() {
    int n;

    // Accept number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar(); // To consume the newline character after entering n

    // Dynamically allocate memory for an array of students
    struct Student **students = (struct Student **)malloc(n * sizeof(struct Student *));
    
    // Input details for each student
    for (int i = 0; i < n; i++) {
        students[i] = createStudent();
        acceptDetails(students[i]);
    }

    // Display student details in a well-formatted manner
    printf("\n--- Student Details ---\n");
    printf("%-20s", "Name"); // Header for Name
    for (int j = 0; j < students[0]->num_marks; j++) {
        printf("%-8s", "Mark"); // Header for Marks
    }
    printf("\n");

    // Display the details
    for (int i = 0; i < n; i++) {
        displayDetails(students[i]);
    }

    // Free the allocated memory for each student
    for (int i = 0; i < n; i++) {
        freeStudent(students[i]);
    }

    // Free the array of student pointers
    free(students);

    return 0;
}