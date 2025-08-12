#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *lptr;
    struct node *rptr;
    int data;
};
struct node * root=NULL;
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    root= newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        root= createNode(data);
    }
    if (data < root->data) {
        root->lptr = insert(root->lptr, data);
    } else if (data > root->data) {
        root->rptr = insert(root->rptr, data);
    }
    return root;
}
void inorder(struct node* root){
    while(root==NULL){
        inorder(root->lptr);
        printf ("%d",root->data);
        inorder(root->rptr);
    }
    
    


}
void display(struct node* root) {
    if (root != NULL) {
        display(root->lptr);
        printf("%d ", root->data);
        display(root->rptr);
    }
}


int main() {
    struct node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 6);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 340);
    root = insert(root, 45);
display(root);
    inorder(root);
  
    return 0;
}
