#include <stdio.h>

void main() {
    int number;

   
    printf("Enter an integer: ");
    scanf("%d", &number);

   
    if (number % 2 == 0)
        printf("%d is Even.\n", number);
    else
        printf("%d is Odd.\n", number);

    
}
