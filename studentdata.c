#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
struct Student {
    char *name;
    int *marks;
    int num_marks;
    struct Student *next;
};

// Function to create a new student node
struct Student* createStudent(char *name, int *marks, int num_marks) {
    struct Student* newStudent = (struct Student*) malloc(sizeof(struct Student));
    newStudent->name = name;
    newStudent->marks = marks;
    newStudent->num_marks = num_marks;
    newStudent->next = NULL;
    return newStudent;
}

// Function to add a student to the linked list
void addStudent(struct Student** head, char *name, int *marks, int num_marks) {
    struct Student* newStudent = createStudent(name, marks, num_marks);
    newStudent->next = *head;
    *head = newStudent;
}

// Function to calculate the average marks for a single student
float calculateStudentAverage(int *marks, int num_marks) {
    int totalMarks = 0;
    for (int i = 0; i < num_marks; i++) {
        totalMarks += marks[i];
    }
    return (num_marks == 0) ? 0 : (float)totalMarks / num_marks;
}

// Function to print student details and their average marks
void printStudentAverages(struct Student* head) {
    struct Student* temp = head;
    while (temp != NULL) {
        printf("Student: %s, Average Marks: %.2f\n", temp->name, calculateStudentAverage(temp->marks, temp->num_marks));
        temp = temp->next;
    }
}

// Function to free the allocated memory
void freeStudents(struct Student* head) {
    struct Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->name);
        free(temp->marks);
        free(temp);
    }
}

int main() {
    struct Student* head = NULL;
    char *name = NULL;
    size_t len = 0;
    int n, num_marks;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar();  // To consume the newline left by scanf

    for (int i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i + 1);
        getline(&name, &len, stdin);
        name[strcspn(name, "\n")] = '\0';  // Remove newline character
        
        printf("Enter the number of marks for student %d: ", i + 1);
        scanf("%d", &num_marks);
        int *marks = (int*) malloc(num_marks * sizeof(int));
        
        for (int j = 0; j < num_marks; j++) {
            printf("Enter mark %d: ", j + 1);
            scanf("%d", &marks[j]);
        }
        getchar();  // To consume the newline left by scanf
        
        // Duplicate the name to avoid issues with getline's reallocation
        char *nameCopy = strdup(name);
        addStudent(&head, nameCopy, marks, num_marks);
    }

    // Print the average marks for each student
    printStudentAverages(head);

    free(name);  // Free the buffer used by getline
    freeStudents(head);  // Free the allocated memory for the linked list

    return 0;
}