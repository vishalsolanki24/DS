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

void insertAtFirst(int data) {
    struct node* newNode = createNode(data);
    if (first == NULL) {
        first = last = newNode;
    } else {
        newNode->rptr = first;
        first->lptr = newNode;
        first = newNode;
    }
}

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

void deleteFromFirst() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = first;
    if (first == last) {
        first = last = NULL;
    } else {
        first = first->rptr;
        first->lptr = NULL;
    }
    free(temp);
    printf("Deleted from beginning.\n");
}

void deleteFromLast() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = last;
    if (first == last) {
        first = last = NULL;
    } else {
        last = last->lptr;
        last->rptr = NULL;
    }
    free(temp);
    printf("Deleted from end.\n");
}

void deleteFromPosition(int position) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    struct node* temp = first;
    int i = 1;

    
    while (temp != NULL && i < position) {
        temp = temp->rptr;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    
    if (temp == first) {
        deleteFromFirst();
        return;
    }

    
    if (temp == last) {
        deleteFromLast();
        return;
    }

    
    temp->lptr->rptr = temp->rptr;
    temp->rptr->lptr = temp->lptr;
    free(temp);
    printf("Deleted node at position %d.\n", position);
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
    int n, data, position;

       
             
    printf("Enter number of elements to insert at beginning: ");
    scanf("%d", &n);
    printf("Enter %d data values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtLast(data);
    }
                printf("Enter position to delete (1-based index): ");
                scanf("%d", &position);
                deleteFromPosition(position);
                printList();
    
    }
        