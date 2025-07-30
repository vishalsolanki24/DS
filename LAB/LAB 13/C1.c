#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
struct Node* swapPairs(struct Node* head) {
    struct Node dummy;
    dummy.next = head;
    struct Node* prev = &dummy;

    while (prev->next != NULL && prev->next->next != NULL) {
        struct Node* first = prev->next;
        struct Node* second = first->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
    }

    return dummy.next;
}
int main() {
    struct Node* head= createNode(1);
    struct Node* temp = head;
    for (int i = 2; i <= 8; i++) {
        temp->next = createNode(i);
        temp = temp->next;
    }

    printf("Original list:\n");
    printList(head);

    head = swapPairs(head);

    printf("\nList after swapping consecutive nodes:\n");
    printList(head);

    return 0;
}
