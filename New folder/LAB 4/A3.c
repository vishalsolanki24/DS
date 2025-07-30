
#include <stdio.h>

void main() {
    int arr[100], n, i, num, pos;
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &n);
    printf("Enter %d elements in ascending order:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    for(pos = 0; pos < n; pos++) {
        if(arr[pos] > num) {
            break;
        }
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
