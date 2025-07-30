#include <stdio.h>
void main (){
	int arr1[3][2];
		int arr2[2][3];
		int sum =0;
		int arr[3][3];
	int i,j,k;
	for ( i=0;i<3;i++){
		for (j=0;j<2;j++){
			scanf("%d",&arr1[i][j]);
		}
	}
		for (  i=0;i<2;i++){
		for (j=0;j<3;j++){
			scanf("%d",&arr2[i][j]);
		}
	}
		for (i=0;i<3;i++){
			for (j=0;j<3;j++){
				for(k=0;k<2;k++){
					arr[i][j]+=arr1[i][k]*arr2[k][j];
					printf ("%d\n",arr[i][j]);
				}
//			sum=(arr1[i][j]*arr2[i][j])+(arr1[i][j+1]*arr2[i+1][j]);
//			printf ("%d\n",sum);
			   }
			}
		
}
