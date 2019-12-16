/* Rightmost Non-Zero Number of a Factorial */

#include<stdio.h>
long Factorial(int n);
void Rightcheck(long n);
void main(){
	int n;
	printf("Enter a number for whose factorial rightmost non-zero value is to be shown: ");
	scanf("%d",&n);
	long f=Factorial(n);
	Rightcheck(f);
}
long Factorial(int n){
	/* To calculate the factorial of a given number */
	long prod=1;
	while(n>=1){
		prod*=n;
		--n;
		}
	return prod;
}
void Rightcheck(long n){
	/* To find the rightmost non zero digit of a given number.*/
	int d=0;
	for(n;n>0;n/=10){
		d=n%10;
		if(d!=0){
			printf("The rightmost non-zero number is: %d",d);
			break;			
		}	
	}
}

/*
[root@sel-25 Desktop]# gcc 26-Rightmost.c -o r
[root@sel-25 Desktop]# ./r
Enter a number for whose factorial rightmost non-zero value is to be shown: 5
The rightmost non-zero number is: 2
*/