#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *lptr;
    struct node *rptr;
    int data;
};

struct node *first = NULL, *last = NULL;

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

void insertAtLast(int data) {
    struct node* newNode = createNode(data);
    if (first == NULL) {
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

void deleteAlternateNodes() {
    if (first == NULL) {
        printf ( "link is amtey:");

    }

    struct node* current = first->rptr; 
    struct node* temp;

    int count = 1;
    while (current != NULL) {
        temp = current;
        current = current->rptr;
        if (temp->lptr != NULL){

            temp->lptr->rptr = temp->rptr;
        }
        if (temp->rptr != NULL){

            temp->rptr->lptr = temp->lptr;
        }
        else{

            last = temp->lptr;  
        }

        free(temp);

        if (current != NULL){

            current = current->rptr; 
        }
    }

    printf("Alternate nodes deleted.\n");
}

int main() {
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtLast(data);
    }

    printf("Original List:\n"); 
    printList();

    deleteAlternateNodes();

    printf("After deleting alternate nodes:\n");
    printList();

    return 0;
}
