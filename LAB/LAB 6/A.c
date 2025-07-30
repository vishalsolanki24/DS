#include <stdio.h>
#define size 100

int top = -1;
int stack[size];

void push(int x) {
    if (top >= size - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
        printf("Push: %d\n", x);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
      
    } else {
        int val = stack[top--];
        printf("Pop: %d\n", val);
        return val;
    }
}

void peep(int position) {
    int index = top - position + 1;
    if (index < 0 || index > top) {
        printf("Invalid position (Underflow)\n");
    } else {
        printf("Element at position %d : %d\n", position, stack[index]);
    }
}

void change(int position, int newValue) {
    int index = top - position + 1;
    if (index < 0 || index > top) {
        printf("Invalid position to change\n");
    } else {
        stack[index] = newValue;
        printf("Changed element at position %d  %d\n", position, newValue);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements : ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(30);
    push(50);
    push(40);
    display();

    pop();
    display();

    peep(1);     
    change(2, 99); 
    display();

    return 0;
}
