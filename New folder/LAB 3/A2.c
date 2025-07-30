#include <stdio.h>
void main (){
	int m,n;
	printf ("enter a m:");
	scanf ("%d",&m);
	printf ("enter a n:");
	scanf ("%d",&n);
	int sum =0;
	int i;
	for (i=m;i<n;i++){
		sum=sum+i;
	}
	printf ("%d",sum);
}
