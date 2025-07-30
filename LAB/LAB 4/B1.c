#include <stdio.h>

void  main() {
    int arr[100], n, i, num, pos = -1;
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &n);
    printf("Enter %d elements in ascending order:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to delete: ");
    scanf("%d", &num);
    for(i = 0; i < n; i++) {
        if(arr[i] == num) {
            pos = i;
            break;
        }
    }
    if(pos != -1) {
        for(i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; 
        printf("Array after deletion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Number not found in the array.\n");
    }
}
