#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int gcd(int a, int b) {
    if (b == 0){

        return a;
    }
    return gcd(b, a % b);
}


void insertEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}


void insertGCDNodes(struct node* head) {
    struct node* current = head;
    while (current != NULL && current->next != NULL) {
        int g = gcd(current->data, current->next->data);
        struct node* gcdNode = createNode(g);
        gcdNode->next = current->next;
        current->next = gcdNode;
        current = gcdNode->next; 
    }
}


void printList(struct node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}


int main() {
    struct node* head = NULL;

    
    insertEnd(&head, 10);
    insertEnd(&head, 30);
    insertEnd(&head, 20);

    printf("Original List:\n");
    printList(head);

    insertGCDNodes(head);

    printf("List After Inserting GCD Nodes:\n");
    printList(head);

    return 0;
}