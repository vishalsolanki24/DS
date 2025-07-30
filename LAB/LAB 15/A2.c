#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *lptr;
    struct node *rptr;
    int data;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

struct node *first = NULL;
struct node *last = NULL;
void insertAtLast(int data) {
    struct node* newNode = createNode(data);
    if (last == NULL) {
        first = last = newNode;
    } else {
        last->rptr = newNode;
        newNode->lptr = last;
        last = newNode;
    }
}
void printList() {
    struct node* temp = first;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->rptr;
    }
    printf("\n");
}
int main() {
    int n, data;
    printf("Enter number of elements to insert at beginning: ");
    scanf("%d", &n);
    printf("Enter %d data values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtLast(data);
    }

    printList();
    return 0;
}

