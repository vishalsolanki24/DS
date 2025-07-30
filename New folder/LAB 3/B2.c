#include <stdio.h>

void main() {
    int arr[100], n, i, oldNum, newNum;
    int found = 0;

    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to be replaced: ");
    scanf("%d", &oldNum);
    printf("Enter the new number: ");
    scanf("%d", &newNum);

  
    printf("Replacing %d with %d at positions: ", oldNum, newNum);
    for(i = 0; i < n; i++) {
        if(arr[i] == oldNum) {
            arr[i] = newNum;
            printf("%d ", i);  
            found = 1;
        }
    }

    if (!found) {
        printf("None (number not found in array)");
    }

    printf("\nFinal array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


}
