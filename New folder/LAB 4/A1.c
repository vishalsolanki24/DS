#include <stdio.h>

void main() {
    int arr[100], n, i, num, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    printf("Enter the position (0 to %d): ", n);
    scanf("%d", &pos);
    if(pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return 1;
    }
    for(i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    n++;  
    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}
