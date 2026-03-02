#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;        
    int exp;         
    struct Node *next;
};
struct Node* createNode(int coef, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertTerm(struct Node* head, int coef, int exp) {
    struct Node* newNode = createNode(coef, exp);
    if (head == NULL || exp > head->exp) {
        newNode->next = head;
        head = newNode;
    }
    else {
        struct Node* temp = head;
        while (temp->next != NULL && temp->next->exp >= exp) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
void displayPoly(struct Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->next;
        if (temp != NULL && temp->coef >= 0)
            printf(" + ");
    }
    printf("\n");
}
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            result = insertTerm(result, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp) {
            result = insertTerm(result, p2->coef, p2->exp);
            p2 = p2->next;
        }
        else {
            int sumCoef = p1->coef + p2->coef;
            if (sumCoef != 0)  
                result = insertTerm(result, sumCoef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insertTerm(result, p1->coef, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertTerm(result, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    int n, coef, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coef, &exp);
        poly1 = insertTerm(poly1, coef, exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coef, &exp);
        poly2 = insertTerm(poly2, coef, exp);
    }

    printf("\nFirst Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    sum = addPoly(poly1, poly2);

    printf("Sum Polynomial: ");
    displayPoly(sum);

    return 0;
}
