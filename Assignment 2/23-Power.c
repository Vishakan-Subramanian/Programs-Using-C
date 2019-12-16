/* Power Function */

#include<stdio.h>
double PowerFun(float x, int n);
void main(){
	float x;
	int n;
	double prod;
	printf("Enter a number: ");
	scanf("%f",&x);
	printf("\nEnter a number to which it should be raised: ");
	scanf("%d",&n);
	prod=PowerFun(x,n);
	printf("The result is: %f",prod);
}
double PowerFun(float x, int n){
	/*To calculate the power of a floating point number */
	double prod=1;
	while(n>0){
		prod=prod*x;
		--n;			
		}
	return prod;
}

/*
[root@sel-25 Desktop]# gcc 24-Power.c -o p
[root@sel-25 Desktop]# ./p
Enter a number: 7.5

Enter a number to which it should be raised: 5
The result is: 23730.468750
*/
