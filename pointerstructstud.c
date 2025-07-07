#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    return newStudent;
}

// Function to accept student details
void acceptDetails(struct Student *student) {
    size_t len = 0;

    // Dynamically allocate memory and accept the student's name using getline
    printf("Enter student's name: ");
    getline(&(student->name), &len, stdin);  // Dynamically allocates memory for the name

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
    printf("\nStudent Name: %s", student->name);  // Name already has a newline due to getline
    printf("Marks: ");
    for (int i = 0; i < student->num_marks; i++) {
        printf("%d ", student->marks[i]);
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