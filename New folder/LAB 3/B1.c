#include <stdio.h>

void main() {
    int arr[100], n, i, j, duplicateFound = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

   
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                duplicateFound = 1;
                break;
            }
        }
        if(duplicateFound){

            break;
        }
    }

    
    if(duplicateFound){

        printf("Duplicate number found in the array.\n");
    }
        
    else{
        printf("No duplicate number in the array.\n");

    }

}
