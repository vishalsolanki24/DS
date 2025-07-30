#include <stdio.h>
void main (){
	int i;
	int n;
	printf ("enter n  number:");
	scanf ("%d",&n);
	int avg=0;
	int sum=0;
	for (i=0; i<=n;i++){
		sum=sum+i;
	}
	avg=sum/n;
	printf ("%d",avg);
}
