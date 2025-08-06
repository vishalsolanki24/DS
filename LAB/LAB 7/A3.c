#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int top =-1;
char s[100];
void push(int ch) {
    
    s[++top] = ch;
}
int pop() {
    top--;
    return s[top];
}
void eval(char infix[]){
     int top=-1;
    //  int ans=0;
     for(int i=0;strlen(infix);i++){
        // char temp=infix[i];
        if (isdigit(infix[i])){
            push(infix[i]-'0');
        }
        else{
            int operand2=pop();
            int operand1=pop();
            switch(infix[i]){
                case'+':{
                    push(operand1 + operand2);
                    break;
                }
                 case'-':{
                    push(operand1 - operand2);
                    break;
                }
                 case'*':{
                    push(operand1 * operand2);
                    break;
                }
                 case'/':{
                    push(operand1 /operand2);
                    break;
                }
                case'^':{
                    push(pow(operand1,operand2));
                    break;
                }
            }

        }
     }


}
void main(){
    char infix[100];
    printf ("enter a string:");
    scanf("%c",infix);
    eval(infix);
    printf("Answer : %d",pop());
}