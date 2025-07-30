#include <stdio.h>
#include <stdlib.h>
struct PolyNode {
    int coeff;
    int expo;
    struct PolyNode* next;
};

struct PolyNode* createNode(int coeff, int expo) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}
void insertTerm(struct PolyNode** poly, int coeff, int expo) {
    struct PolyNode* newNode = createNode(coeff, expo);
    
    if (*poly == NULL || expo > (*poly)->expo) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct PolyNode* temp = *poly;
        while (temp->next != NULL && temp->next->expo > expo)
            temp = temp->next;

        if (temp->next != NULL && temp->next->expo == expo) {
            temp->next->coeff += coeff;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}
struct PolyNode* addPolynomials(struct PolyNode* poly1, struct PolyNode* poly2) {
    struct PolyNode* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->expo == poly2->expo) {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->expo > poly2->expo) {
            insertTerm(&result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else {
            insertTerm(&result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }

    return result;
}
void printPolynomial(struct PolyNode* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->expo);
        if (poly->next != NULL) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}


int main() {
    struct PolyNode* poly1 = NULL;
    struct PolyNode* poly2 = NULL;
    struct PolyNode* sum = NULL;

    
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);
    insertTerm(&poly2, 5, 1);
    insertTerm(&poly2, 5, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    printPolynomial(sum);

    return 0;
}
