#include <stdio.h>

void main() {
    int n, i;
    int totalSum = 0;

   
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        totalSum += (i * (i + 1)) / 2;
    }

    printf("Sum of the series is: %d\n", totalSum);

}
