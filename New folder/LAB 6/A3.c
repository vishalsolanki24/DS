#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char stack1[100];
    char stack2[100];
    int i = 0, stack1_index = 0, stack2_index = 0;
    int valid = 1;

    printf("Enter the string: ");
    scanf("%s", input);
    while (input[i] == 'a') {
        stack1[stack1_index++] = input[i++];
    }
    stack1[stack1_index] = '\0'; 
    if (stack1_index == 0) {
        valid = 0; 
    }

    
    while (input[i] == 'b') {
        stack2[stack2_index++] = input[i++];
    }
    stack2[stack2_index] = '\0'; 

    if (stack2_index == 0) {
        valid = 0; 
    }

   
    if (input[i] != '\0') {
        valid = 0;
    }
    if (stack1_index != stack2_index) {
        valid = 0;
    }

    if (valid) {
        printf("Valid string \n");
    } else {
        printf("Invalid string\n");
    }

    return 0;
}
