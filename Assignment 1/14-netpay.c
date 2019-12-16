//to find the net salary of an employee
#include<stdio.h>
void main(){
	float bp,da,hra,pf,np,ded,gp;
	printf("Enter the basic pay of the employee: ");
	scanf("%f",&bp);
	da=0.88*bp;
	hra=0.08*bp;
	pf=0.1*bp;
	gp=bp+da+hra+1000.0;
	ded=2000.0+pf;
	np=gp-ded;
	printf("The net salary of the employee is %f",np);
}

/*
[cse1196@sel-25 A1]$ gcc 14-netpay.c -o n
[cse1196@sel-25 A1]$ ./n
Enter the basic pay of the employee: 10000
The net salary of the employee is 17600
*/
