#include <stdio.h>
#include <math.h>

void main() {
    int num, temp, rem, sum, digits;

    printf("Armstrong numbers between 1 and 1000 are:\n");

    for (num = 1; num <= 1000; num++) {
        temp = num;
        sum = 0;

        digits = 0;
        int n = temp;
        while (n != 0) {
            n /= 10;
            digits++;
        }

        n = temp;
        while (n != 0) {
            rem = n % 10;
            sum += pow(rem, digits);
            n /= 10;
        }

        if (sum == num) {
            printf("%d ", num);
        }
    }

}
