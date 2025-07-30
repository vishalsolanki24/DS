
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* first = NULL;
struct node* last = NULL;


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void insertintoLAST(int data) {
    struct node* newNode = createNode(data);
    if (first == NULL) {
        first = newNode;
        last = newNode;
        newNode->link = first; 
    } else {
        last->link = newNode;
        last = newNode;
        last->link = first; 
    }
}


void cirfirst(int data) {
    struct node* newNode = createNode(data);
    if (first == NULL) {
        first = newNode;
        last = newNode;
        newNode->link = first;
    } else {
        newNode->link = first;
        last->link = newNode;
        first = newNode;
    }
}


void printList() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    struct node* temp = first;
   
    while(temp!=first){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int n, data;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertintoLAST(data);
    }

    printf("Enter element in first: ");
    scanf("%d", &data);
    cirfirst(data);
    printList();

    return 0;
}
