#include <stdio.h>
#include <stdlib.h>

struct Node {
    char name[50];
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node with name input via getchar()
struct Node* createNode() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter name: ");
    
    // Reading name using getchar() without string library functions
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < 49) {
        newNode->name[i++] = ch;
    }
    newNode->name[i] = '\0';  // Null-terminate the string
    newNode->next = newNode;  // Point to itself for circular linking
    return newNode;
}

// Insert a node at any position
void insertAtPosition(int pos) {
    struct Node* newNode = createNode();
    if (head == NULL) {
        head = newNode;
    } else if (pos == 1) {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == head) {
                printf("Position out of range\n");
                free(newNode);
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted at position %d\n", pos);
}

// Delete a node at any position
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    if (pos == 1) {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        if (head->next == head) {  // Only one node
            free(head);
            head = NULL;
        } else {
            last->next = head->next;
            head = head->next;
            free(temp);
        }
    } else {
        struct Node* prev = NULL;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
            if (temp == head) {
                printf("Position out of range\n");
                return;
            }
        }
        prev->next = temp->next;
        free(temp);
    }
    printf("Node deleted at position %d\n", pos);
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%s -> ", temp->name);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Modify a node at any position
void modifyAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range\n");
            return;
        }
    }
    printf("Enter new name for position %d: ", pos);
    
    // Clear previous input buffer and read new name
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < 49) {
        temp->name[i++] = ch;
    }
    temp->name[i] = '\0';  // Null-terminate the string
    printf("Node modified at position %d\n", pos);
}

int main() {
    int choice, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Position\n");
        printf("2. Delete at Position\n");
        printf("3. Display List\n");
        printf("4. Modify at Position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                getchar();  // Consume newline left by scanf
                insertAtPosition(pos);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                getchar();  // Consume newline left by scanf
                deleteAtPosition(pos);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Enter position to modify: ");
                scanf("%d", &pos);
                getchar();  // Consume newline left by scanf
                modifyAtPosition(pos);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
