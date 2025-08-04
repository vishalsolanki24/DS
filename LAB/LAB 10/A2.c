#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int pos) {
    if (head == NULL || pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        deleteFirst();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    printf("Total Nodes = %d\n", count);
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at front\n2. Display\n3. Delete first node\n4. Insert at end\n");
        printf("5. Delete last node\n6. Delete at position\n7. Count nodes\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                display();
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                countNodes();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

}
