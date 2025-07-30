#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * link;
};
struct node* top = NULL;

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}
void queuepush(int data){
     struct node* newNode = createNode(data);
      struct node* temp=top;
     if (top==NULL){
        top=newNode;
     }
    else{
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
    }
     

void queuepop(){
    struct node* temp= top;
    if(top== NULL){
        printf("stack is underflov");
    }
    else{
        struct node* temp = top;
        struct node* prev = NULL;

        while (temp->link != NULL) {
            prev = temp;
            temp = temp->link;
        }

        prev->link = NULL;
        free(temp);
    }
}
void printList(){
    printf("Linked List :\n");
    struct node * temp = top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
int main()
{
    printf("Enter size of Linked List");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        printf("%d th node value ",i+1);
        scanf("%d",&data);
        queuepush(data);
    }
    queuepop();
    printList();
    
   
}