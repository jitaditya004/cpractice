#include<stdio.h>
#include<stdlib.h>

#define max 100

typedef struct Node {
    char name[max];
    struct Node* prev;
    struct Node* next;
} node;

node* head = NULL;

node* create(char* name) {
    node* new = (node*)malloc(sizeof(node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    int i = 0;
    while (name[i] != '\0' && i < max - 1) {  // Fixed string copy condition
        new->name[i] = name[i];
        i++;
    }
    new->name[i] = '\0';
    new->prev = NULL;
    new->next = NULL;
    
    return new;
}

void insertany(char* name, int pos) {
    node* new = create(name);
    
    if (pos == 1) {  // Insert at the head
        new->next = head;
        if (head != NULL) {
            head->prev = new;
        }
        head = new;
        return;
    } else {
        int i = 1;
        node* temp = head;
        while (temp != NULL && i < pos) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Position not found\n");
            free(new);
            return;
        }
        if (temp->next != NULL) {
            temp->next->prev = new;
        }
        new->next = temp->next;
        temp->next = new;
        new->prev = temp;
        printf("Inserted\n");
    }
}

void delany(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {  // Deleting head
        node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    } else {
        node* temp = head;
        int i = 1;
        while (temp != NULL && i < pos) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Position not found\n");
            return;
        }
        node* del = temp;
        if (del->next != NULL) {
            del->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        free(del);
        printf("Deleted\n");
    }
}

void search(char* str) {
    node* temp = head;
    while (temp != NULL) {
        int i = 0;
        int match = 1;
        while (temp->name[i] != '\0' && str[i] != '\0') {
            if (temp->name[i] != str[i]) {
                match = 0;
                break;
            }
            i++;
        }
        if (match && temp->name[i] == '\0' && str[i] == '\0') {
            printf("Found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Not found\n");
}

void disp() {
    node* temp = head;
    while (temp != NULL) {
        printf("%s -- ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, pos;
    char name[max];
    
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();  // Clear newline after scanf
    
    switch(choice) {
        case 1:
            printf("Enter name and position: ");
            fgets(name, max, stdin);
            //name[strcspn(name, "\n")] = 0;  // Remove newline character
            int len=0;//use brackets, fgets null terminate if space aviable
if(name[len] != '\0')
{
len++;
}
if(len>0 && name[len-1] == '\n')
{
name[len-1] = '\0';
}

            scanf("%d", &pos);
            insertany(name, pos);
            break;

        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            delany(pos);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }
    
    return 0;
}
