#include <stdio.h>
void main (){
	int n;
	int i;
	int max;
	int min;
	int maxn=0,minn=0;
    printf ("enter n number ");
    scanf ("%d",&n);
    int arr[n];
	for (i=0;i<=n;i++){
			 scanf ("%d",&arr[i]);
			 
			 if (i==0){
			 	max =min=arr[i];
			 	
			 }
			 else{
			 	if (arr[i]<max){
			 		max=arr[i];
			 		minn=i;
				 }
				if (arr[i]<min){
					min =arr[i];
					maxn=i;
				}
			 }
	}
	printf ("%d",maxn);
	printf ("%d",minn);
	printf ("%d",max);
	printf ("%d",min);
	
	
}
