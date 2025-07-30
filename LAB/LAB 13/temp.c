#include <stdio.h>

void main(){
    int n = 5;

    for(int i=0;i<n;i++){
        int counter = 0;
        for(int j=0;j<((2*i)-1);j++){
            if(counter == 0 || counter == n){
                printf("1 ");
                counter++;
            }
            else if(counter == (n+1)/2){
                printf("%d ",counter);
                counter++;
            }
            else{
                printf("* ");
                counter++;
            }
        }
        printf("\n");
    }
}