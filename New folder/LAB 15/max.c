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
int *max=NULL;
struct node* temp = first;
void insertAtFirst(int data) {
    struct node* newNode = createNode(data);
    if (first == NULL) {
        first = newNode;
        last = newNode;
    } else {
        newNode->rptr = first;
        first->lptr = newNode;
        first = newNode;
    }
}
void max(){
    struct node* temp = first;
    while (temp!=  NULL){
        temp = temp->rptr;
       if (temp->data > max){
        temp->data=max;
       }
        
    }
    return max;
}
void printList() {
    printf("Doubly Linked List:\n");
    struct node* temp = first;
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
        insertAtFirst(data);
    }
    max();
    printList();
    return 0;
}
