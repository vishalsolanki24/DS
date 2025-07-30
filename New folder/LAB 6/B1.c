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
   
    
        if(ch == '{' || ch =='[' ||ch == '('){
            push(stack[top]);
        }
        else if(ch == '}'||ch ==']' || ch == ')'){
            pop();

        }
        else if (ch=')'){
            int x=pop();
            if (x!=')'){
                return 1;
            }
        }
        else if (ch=']'){
            int x=pop();
            if (x!=']'){
                return 1;
            }
        }
        else if (ch='}'){
            int x=pop();
            if (x!='}'){
                return 1;
            }
        }
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
     validetion('');
     check();


}
