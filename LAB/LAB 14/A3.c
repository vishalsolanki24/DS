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

void insertEnd(int data) {
    struct node* newNode = createNode(data);
    if (first == NULL) {
        first = last = newNode;
        last->link = first;
    } else {
        last->link = newNode;
        last = newNode;
        last->link = first;
    }
}

void display() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = first;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != first);
    printf("(back to first)\n");
}

void deleteAtPosition(int pos) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    int count = 1;
    struct node *temp = first, *prev = NULL;

   
    struct node* countNode = first;
    int total = 0;
    do {
        total++;
        countNode = countNode->link;
    } while (countNode != first);

    if (pos < 1 || pos > total) {
        printf("Invalid position\n");
        return;
    }

    
    if (pos == 1) {
        if (first == last) {
            free(first);
            first = last = NULL;
        } else {
            struct node* temp = first;
            first = first->link;
            last->link = first;
            free(temp);
        }
    } else {
        while (count < pos) {
            prev = temp;
            temp = temp->link;
            count++;
        }

        prev->link = temp->link;
        if (temp == last) {
            last = prev;
        }
        free(temp);
    }

    
}


int main() {
    int n, data;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(data);
    }
int pos;
    printf("Enter element in delet: ");
    scanf("%d", &pos);
    deleteAtPosition(pos);
    display();

    return 0;
}