/*Find the product of nfloating point numbers. The numbers should be 
read from the keyboard. You should not use any looping construct. [Hint: use recursion and decide a suitable sentinel for termination of recursion */

#include<stdio.h>
float Product(int n);
void main()
{
int n;
float prod=1;
printf("Enter the number of terms to be multiplied: ");
scanf("%d",&n);
prod=Product(n);
printf("The final answer is: %f",prod);
}
float Product(int n){
	/* To calculate the product of N numbers, which are to be entered by the user. */
	float num=0;
	if(n>0){
		printf("\nEnter a value to multiply:");
		scanf("%f",&num);
		return Product(n-1)*num;
		}		
	else{
		return 1;
	}	
	}
	
/*
[root@sel-25 Desktop]# gcc 24-Product.c -o pr
[root@sel-25 Desktop]# ./pr
Enter the number of terms to be multiplied: 4

Enter a value to multiply:1.5

Enter a value to multiply:2.5

Enter a value to multiply:3.5

Enter a value to multiply:4.5
The final answer is: 59.062500

*/
