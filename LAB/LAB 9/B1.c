#include <stdio.h>

void sort(int *arr, int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
}

int main() {
    int arr[5], *ptr = arr;
    printf("Enter 5 numbers:\n");
    for(int i = 0; i < 5; i++)
        scanf("%d", ptr + i);

    sort(ptr, 5);

    printf("Sorted array:\n");
    for(int i = 0; i < 5; i++)
        printf("%d ", *(ptr + i));

    return 0;
}
