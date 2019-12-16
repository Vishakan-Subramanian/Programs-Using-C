//to find the net salary of an employee, based on city and designation.
#include<stdio.h>
void main(){
	float bp,da,hra,pf,np,ded,cca,gp,c,w;

	printf("Enter the basic pay of the employee: ");
	scanf("%f",&bp);
	
	printf("Enter the type of city.\n 1 for Metro \n 2 for Corporation \n 3 for Taluk \n");
	scanf("%f",&c);

	printf("Enter the designation.\n W for Worker \n E for Engineer \n M for Manager \n");
	scanf("%f",&w);

	if(c==1) 
		hra=0.1*bp; 
	else if(c==2) 
		hra=0.08*bp; 
	else if(c==3)
		hra=0.05*bp; 
	else 
		printf("Invalid option for city."); 

	if(w==1)
		cca=1000; 
	else if(w==2) 
		cca=2000; 
	else if(w==3) 
		cca=5000; 
	else 
		printf("Invalid option for designation."); 
 
	da=0.88*bp;
	hra=0.08*bp;
	pf=0.1*bp;
	gp=bp+da+hra+cca;
	ded=2000.0+pf;
	np=gp-ded;
	printf("The net salary of the employee is %f",np);


}
/*
[cse1196@sel-25 A1]$ gcc netpaymod.c -o nm
[cse1196@sel-25 A1]$ ./nm
Enter the basic pay of the employee: 10000
Enter the type of city.
 1 for Metro 
 2 for Corporation 
 3 for Taluk
1
Enter the designation.
 1 for Worker 
 2 for Engineer 
 3 for Manager
1
The net salary of the employee is 17600 */
