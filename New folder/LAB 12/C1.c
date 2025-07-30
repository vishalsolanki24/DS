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
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void swapKthNode(struct Node** head_ref, int k) {
    int n = countNodes(*head_ref);
    if (k > n || k <= 0){
        return ;
    }
        
    if (2 * k - 1 == n){

        return;
    }
    struct Node* x = *head_ref;
    struct Node* x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }
    struct Node* y = *head_ref;
    struct Node* y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }
    if (x_prev){

        x_prev->next = y;
    }
    else{

        *head_ref = y;
    }
    if (y_prev){

        y_prev->next = x;
    }
    else{
        *head_ref = x;
    }
        

    
    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
}
int main() {
   
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List:\n");
    printList(head);

    int k = 2;
    swapKthNode(&head, k);

    printf("\nList after swapping %dth node from beginning and end:\n", k);
    printList(head);

    return 0;
}
