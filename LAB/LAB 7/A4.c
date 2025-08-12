#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int stack[100];
int top = -1;
void push(int c){
    stack[++top] = c;
}

int pop(){
    return stack[top--];
}
void eval(char infix[]){
     int top=-1;
    
     for(int i=0;strlen(infix);i++){
     
        if (isdigit(infix[i])){
            push(infix[i]-'0');
        }
        else{
            int operand1=pop();
            int operand2=pop();
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
    char prefix[100];
    printf("Enter a posfix expression :");
    scanf("%s",prefix);
    strrev(prefix);
    eval(prefix);
    printf("Answer : %d",pop());
}