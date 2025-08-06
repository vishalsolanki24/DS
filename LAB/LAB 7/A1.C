#include <stdio.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

int g(char s) {
    if (s == '+' || s == '-'){

        return 2;
    }
    else if (s == '*' || s == '/'){

        return 4;
    } 
    else if (s == '^'){

        return 5;
    } 
    else if (s == '(') {

        return 0;
    }
    else{

        return 8;
    } 
}

int f(char s) {
    if (s == '+' || s == '-') {
        return 1;}
    else if (s == '*' || s == '/') {
        
        return 3;
    }
    else if (s == '^'){

        return 6;
    } 
    else if (s == '('){

        return 9;
    } 
    else{
        return 0;
    }
}
void push(char ch) {
    if (top >= SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ch;
}k
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

void polish(char infix[]) {
    int i = 0;
    char postfix[SIZE];
    int j = 0;

    push('(');  
    strcat(infix, ")");  
    while (infix[i] != '\0') {
        char next = infix[i];

        if (top < 0) {
            printf("Invalid expression\n");
            return;
        }
        if ((next >= 'a' && next <= 'z') || (next >= 'A' && next <= 'Z') || (next >= '0' && next <= '9')) {
            postfix[j++] = next;
        } 
        else {
            while (g(stack[top]) > f(next)) {
                postfix[j++] = pop();
            }

            if (g(stack[top]) != f(next)) {
                push(next);
            } else {
                pop(); 
            }
        }
        i++;
    }

    if (top != -1) {
        printf("Invalid expression\n");
    } else {
        postfix[j] = '\0';
        printf("Postfix expression: %s\n", postfix);
        printf("Valid expression\n");
    }
}

int main() {
    char infix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    polish(infix);
    return 0;
}
