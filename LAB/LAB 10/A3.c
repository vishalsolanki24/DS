#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int areSame(struct Node* a, struct Node* b) {
    while (a && b) {
        if (a->data != b->data)
            return 0;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}

struct Node* createList(int n) {
    struct Node *head = NULL, *temp, *newNode;
    int value;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if (!head)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void main() {
    int n;

    printf("Enter number of nodes for List 1: ");
    scanf("%d", &n);
    struct Node* list1 = createList(n);

    printf("Enter number of nodes for List 2: ");
    scanf("%d", &n);
    struct Node* list2 = createList(n);

    if (areSame(list1, list2)){

        printf("Both lists are same.\n");
    }
    else{

        printf("Lists are different.\n");
    }

  
}
