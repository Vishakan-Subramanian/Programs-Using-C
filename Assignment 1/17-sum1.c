/* sum 1 */

#include<stdio.h>
void main(){
	printf("Version 1\n");
	printf("Enter a number N till which sum is to be done.");
	int n,sum=0;
	scanf("%d",&n);
	sum=n*(n+1)/2;
	printf("The sum is: %d",sum);
}

/*
Version 1
Enter a number N till which sum is to be done.100
The sum is: 5050
 */
