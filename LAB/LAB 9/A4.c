#include <stdio.h>
void main() {
    int arr[5], *ptr;
    ptr = arr;

    printf("Enter 5 elements:\n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", ptr + i);
    }

    int max = *ptr;
    for(int i = 1; i < 5; i++) {
        if (*(ptr + i) > max)
            max = *(ptr + i);
    }

    printf("Largest Element = %d\n", max);
   
}
