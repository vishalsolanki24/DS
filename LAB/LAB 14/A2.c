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


void cirlast(int data) {
    struct node* newNode = createNode(data);
    if (first == NULL) {
        newNode->link = newNode; 
        first = newNode;
        last = newNode;
    } else {
        newNode->link = first;
        last->link = newNode;
        last = newNode;
    }
}


void printList() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = first;
    printf("Circular Linked List:\n");

    do {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != first);

    printf("\n");
}

int main() {
    int n, data;

    printf("Enter size of Linked List: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        cirlast(data);  
    }

    printf("Enter value to insert at last: ");
    scanf("%d", &data);
    cirlast(data);

    printList();

    return 0;
}
