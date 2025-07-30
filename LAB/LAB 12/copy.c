
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* first = NULL;
struct node* first1 = NULL;

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void insertintoLAST(int data) {
    struct node* newNode = createNode(data);
    struct node* save = first;

    if (first == NULL) {
        first = newNode;
    } else {
        while (save->link != NULL) {
            save = save->link;
        }
        save->link = newNode;
    }
}


void insertintoLAST1(int data) {
    struct node* newNode = createNode(data);
    struct node* save = first1;

    if (first1 == NULL) {
        first1 = newNode;
    } else {
        while (save->link != NULL) {
            save = save->link;
        }
        save->link = newNode;
    }
}


void copy() {
    struct node* temp = first;

    while (temp != NULL) {
        insertintoLAST1(temp->data);  
        temp = temp->link;
    }
}

void printList() {
    printf("Original Linked List:\n");
    struct node* temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void printList1() {
    printf("Copied Linked List:\n");
    struct node* temp = first1;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("%d-th node value: ", i + 1);
        scanf("%d", &data);
        insertintoLAST(data);
    }

    copy();

    printList();
    printList1();

}
