#include<stdio.h>
#include<string.h>
#define size 100
int top=-1;
int stack[size];
void push(int x){
    stack[++top] = x;

}
int pop(){
     int val = stack[top--];
     return val;
}
 int validetion(char ch){
   
    
         if (ch == '{' || ch == '[' || ch == '(') {
        push(ch);
    } 
    else if (ch == '}' || ch == ']' || ch == ')') {
        char x = pop();
        if ((ch == ')' && x != '(') ||
            (ch == ']' && x != '[') ||
            (ch == '}' && x != '{')) {
            return 0; // Mismatch
        }
    }
    return 1; // Valid so fa
       
    }
    void check(){
        if (top ==-1){
        printf ("1");
    }
    else{
        printf ("0");

    }

    }
 

 




void main(){
    validetion('(');
    //  validetion('[');
    //  validetion('{');
    //  validetion('}');
    //  validetion('(');
    //  validetion(')');
    //  validetion(']');
    //  validetion(')');
    //  validetion('[');
    //  validetion('{');
    //   validetion('{');
     validetion('{');
     check();


}
