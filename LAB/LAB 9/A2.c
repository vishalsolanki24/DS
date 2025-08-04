#include <stdio.h>

void  main() {
    int arr[5], *ptr;
    ptr = arr;

    printf("Enter 5 elements:\n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", ptr + i);
    }

    printf("You entered:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }

}
