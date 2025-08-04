#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d → ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* createSortedList() {
    int arr[] = {1, 1, 6, 13, 13, 13, 27, 27};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node *head = NULL, *temp = NULL;
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (!head){

            head = newNode;
        }
        else{

            temp->next = newNode;
            temp = newNode;
        }

    }
    return head;
}

int main() {
    struct Node* head = createSortedList();

    printf("Original list:\n");
    display(head);

    removeDuplicates(head);

    printf("After removing duplicates:\n");
    display(head);

    return 0;
}
