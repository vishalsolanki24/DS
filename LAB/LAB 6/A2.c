#include<stdio.h>
#include<string.h>
#define size 100
 int top=-1;
 char stack[size];
 void push(char ch)
{
    if(top<size-1){
        stack[++top]=ch;
    }
}
char pop (){
    if (top>=0){
        return stack[top--];
    }
    return '\0';
}
void recognize(char *str){
    int i=0;
    char next;
    top=-1;
    push('c');
    next=str[i++];
    while(next!='c'){
        if(next == '\0' || next == ' '){
            printf ("string invelide");

        }
        else{
            push(next);
            next=str[i++];
        }
    }

while (stack[top] != 'c') {
        next = str[i++];
        char x = pop();
        if (next != x) {
            printf("Invalid String");
            return;
        }
    }
    next = str[i];
    if (next == '\0' || next == ' ') {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }
    }




int main(){
  
     char *inputs[] = {"aca","bcb","abcba","abbcbba"};
    int n = sizeof(inputs) / sizeof(inputs[0]);
    for (int i = 0; i < n; i++) {
        printf("Testing \"%s\": ", inputs[i]);
        recognize(inputs[i]);
    }
}
