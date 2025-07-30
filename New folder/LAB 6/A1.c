#include <stdio.h>
#define size 100
int top=-1;
int n;

int stack[size];
void push(int x){
    if (top>=size){
        printf ("stack is overflov");

    }
    else{
       
        stack[top +1]=x;
        printf("%d",x);

    }


}
 int pop(){
    if (top==-1){
        printf("stack ander folve");
    }
    else{
        int val = stack[top--];
        printf("Popped: %d\n", val);
        return val;
        
        
    }
 }
 void peep(int positp){
    if (top-positp+1 <=-1){
         printf("stack ander folve");
    }
    else{
        printf ("%d %d",positp,stack[top-positp+1]);
    }
 }
 void change(int positp,int newvalues){
    if(positp<=0 || positp> top+1){
        printf("%d",top+1);
    }
    else{
        stack[top-positp+1]==newvalues;
        printf ("%d %d",positp ,newvalues);
    }
 }
 void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
void main (){
    push(30);
    display();
     push(50);
      push(40);
      
    // pop();
    //   display();
    // peep(1);
    // display();
    // change(2,99);
    // display();
}