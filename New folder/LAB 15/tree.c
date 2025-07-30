#include<stdio.h>
#include <stdlib.h>
struct node {
     struct node *lptr;
    struct node *rptr;
    int data;
};
struct node* createNode(int data) {
    struct node* n1 = (struct node*)malloc(sizeof(struct node));
    n1->data = data;
    n1->lptr = NULL;
    n1->rptr = NULL;
   
    return n1;
}
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->lptr);
        printf("%d ", root->data);
        inorder(root->rptr);
    }
}
int main (){
    struct node* root = createNode(1);
    root->lptr= createNode(2);
    root->rptr = createNode(3);
    root->lptr->lptr = createNode(4);
    root->lptr->rptr = createNode(5);
     printf("Inorder traversal: ");
    inorder(root);
}