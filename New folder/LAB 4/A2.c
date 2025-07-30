
#include <stdio.h>
void main (){
	 int n ,i,num,pos;
     printf ("enter a number:");
     scanf ("%d",&n);
     int arr[n];
     for (i=0;i<n;i++){
        scanf ("%d",&arr[i]);

     }
     
    
     printf ("enter a pos:");
     scanf ("%d",&pos);
     for (i=pos;i<n-1;i++){
                 arr[i]=arr[i+1];
    
     }
  n--;
     for (i=0;i<n;i++){
        printf ("%d",arr[i]);

     }
}

