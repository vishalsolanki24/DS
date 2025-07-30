#include <stdio.h>
void main (){
	int arr1[2][2];
		int arr2[2][2];
		int sum =0;
		int arr[2][2];
	int i,j;
	for ( i=0;i<2;i++){
		for (j=0;j<2;j++){
			scanf("%d",&arr1[i][j]);
		}
	}
	for (  i=0;i<2;i++){
		for (j=0;j<2;j++){
			scanf("%d",&arr2[i][j]);
		}
	}
		for (  i=0;i<2;i++){
		for (j=0;j<2;j++){
			arr[i][j]=arr1[i][j] + arr2[i][j];
				printf (" sum %d\n",arr[i][j]);
		}
	}

	
	
	
}
