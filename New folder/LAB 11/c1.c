#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * link;
};
struct node* last= NULL;
struct node* first = NULL;

struct node* createNode(int data){
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
void duplicate(){
    struct node* i,*j;
     for(i=first;i!= NULL;i=i->link){
            for (j=i->link;j!=  NULL;j=j->link){
              if(i->data!=j->data){
               free(i);
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

int main() {
    int n, data;
    printf("Enter number of elements to insert at beginning: ");
    scanf("%d", &n);
    printf("Enter %d data values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
    insertintoLAST(data);
    }
    
    duplicate();

    printList();
    return 0;
}
