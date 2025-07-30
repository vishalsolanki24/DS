#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* first = NULL;


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}
void insertintoLAST(int data) {
    struct node* newNode = createNode(data);
    struct node* save = first;

    if (first == NULL) {
        first = newNode;
    } else {
        while (save->link != NULL) {
            save = save->link;
        }
        save->link = newNode;
    }
}

void sortList(){
    //  struct node* newNode = createNode(data);
    struct node* save = first;
    struct node* i,*j;
    int temp;
     if (first == NULL) {
        printf ("list is emty:");
    } 
    else{
        for(i=first;i!= NULL;i=i->link){
            for (j=i->link;j!=  NULL;j=j->link){
              if(i->data>j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
              }

            }
        }


    }


}
void printList() {
    printf("Original Linked List:\n");
    struct node* temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
void printList1() {
    printf("sort Linked List:\n");
    struct node* temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
void main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("%d-th node value: ", i + 1);
        scanf("%d", &data);
        insertintoLAST(data);
    }
    printList();
    sortList();
    printList1();
 }
