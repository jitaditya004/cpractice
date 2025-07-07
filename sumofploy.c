#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int coeff;  // Coefficient of the polynomial term
    int exp;    // Exponent of the polynomial term
    struct Node* next;  // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of a linked list
void insertNode(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print a polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d*x^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertNode(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) {
                insertNode(&result, sum, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms of poly1
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    // Add remaining terms of poly2
    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Function to take user input for a polynomial
void inputPolynomial(struct Node** poly) {
    int n, coeff, exp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertNode(poly, coeff, exp);
    }
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    // Input first polynomial
    printf("Enter the first polynomial:\n");
    inputPolynomial(&poly1);

    // Input second polynomial
    printf("Enter the second polynomial:\n");
    inputPolynomial(&poly2);

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    // Display the polynomials
    printf("First Polynomial: ");
    printPolynomial(poly1);
    
    printf("Second Polynomial: ");
    printPolynomial(poly2);

    // Display the result
    printf("Resultant Polynomial after addition: ");
    printPolynomial(result);

    return 0;
}