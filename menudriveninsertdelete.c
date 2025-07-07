#include <stdio.h>
#include <stdlib.h>

// Function to display the menu
void display_menu() {
    printf("\nMenu:\n");
    printf("1. Insert element\n");
    printf("2. Delete element\n");
    printf("3. Update element\n");
    printf("4. Display elements\n");
    printf("5. Exit\n");
}

// Function to insert an element into the array
void insert_element(int **arr, int *size, int element, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    
    *arr = (int *)realloc(*arr, (*size + 1) * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = *size; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[position] = element;
    (*size)++;
}

// Function to delete an element from the array
void delete_element(int **arr, int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    
    *arr = (int *)realloc(*arr, (*size - 1) * sizeof(int));
    if (*arr == NULL && *size > 1) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    (*size)--;
}

// Function to update an element in the array
void update_element(int *arr, int size, int position, int new_value) {
    if (position < 0 || position >= size) {
        printf("Invalid position!\n");
        return;
    }
    
    arr[position] = new_value;
}

// Function to display the elements of the array
void display_elements(int *arr, int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice, element, position;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Insert element
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert at (0 to %d): ", size);
                scanf("%d", &position);
                insert_element(&arr, &size, element, position);
                break;
                
            case 2:  // Delete element
                printf("Enter the position to delete from (0 to %d): ", size - 1);
                scanf("%d", &position);
                delete_element(&arr, &size, position);
                break;
                
            case 3:  // Update element
                printf("Enter the position to update (0 to %d): ", size - 1);
                scanf("%d", &position);
                printf("Enter the new value: ");
                scanf("%d", &element);
                update_element(arr, size, position, element);
                break;
                
            case 4:  // Display elements
                display_elements(arr, size);
                break;
                
            case 5:  // Exit
                free(arr);
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}