#include <stdio.h>
#include <stdlib.h>  // Include stdlib.h for malloc and free

#define MAX_STUDENTS 100  // Define the maximum number of students
#define NUM_MARKS 3       // Define the number of marks each student has

// Define a structure to hold student information
struct Student {
    char name[50];
    float* marks;   // Pointer to dynamically allocate memory for marks
    float average;
};

// Function to input student data
void inputStudentData(struct Student* students, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]%*c", students[i].name);  // Read string with spaces

        // Dynamically allocate memory for the marks array
        students[i].marks = (float*)malloc(NUM_MARKS * sizeof(float));
        if (students[i].marks == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        // Input the marks
        for (int j = 0; j < NUM_MARKS; j++) {
            printf("Enter mark %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
        
        printf("\n");
    }
}

// Function to calculate average marks for each student
void calculateAverages(struct Student* students, int count) {
    for (int i = 0; i < count; i++) {
        float total = 0;
        for (int j = 0; j < NUM_MARKS; j++) {
            total += students[i].marks[j];
        }
        students[i].average = total / NUM_MARKS;  // Calculate average
    }
}

// Function to display student data with average marks
void displayStudentData(struct Student* students, int count) {
    printf("Student Averages:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Average Marks: %.2f\n", students[i].name, students[i].average);
    }
}

// Function to free dynamically allocated memory
void freeMemory(struct Student* students, int count) {
    for (int i = 0; i < count; i++) {
        free(students[i].marks);  // Free the allocated memory for marks
    }
}

int main() {
    int numStudents;

    // Input number of students
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Ensure we do not exceed the maximum limit
    if (numStudents > MAX_STUDENTS) {
        printf("The maximum number of students allowed is %d.\n", MAX_STUDENTS);
        return 1;  // Exit with an error code
    }

    // Declare an array of Student structures
    struct Student students[numStudents];

    // Input student data
    inputStudentData(students, numStudents);

    // Calculate average marks for each student
    calculateAverages(students, numStudents);

    // Display student data with average marks
    displayStudentData(students, numStudents);

    // Free dynamically allocated memory
    freeMemory(students, numStudents);

    return 0;
}