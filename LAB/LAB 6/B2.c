#include<stdio.h>
#include<string.h>
#define size 100

char stack[size];
int top=-1;
void push(int x){
    stack[++top] = x;

}
int pop(){
     int val = stack[top--];
     return val;
}
void processString( char *s){
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='*'){
            pop();
        }else{
            push(s[i]);
        }
    }
    for(int i=0;i<=top;i++){
        printf("%c",stack[i]);
    }
}
int main(){
    char s1[] = "leet**cod*e";
    char s2[] = "erase*****";

    printf("Input: %s\nOutput: ", s1);
    processString(s1); 

    printf("Input: %s\nOutput: ", s2);
    processString(s2); 
return 1;
}
