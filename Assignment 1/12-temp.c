//to change Celsius to Fahrenheit and Kelvin
#include<stdio.h>
void main()
{
	int c,f,k;	
	printf("Enter the value of temperature in Celsius:");
	scanf("%d",&c);
	k=c+273;
	f=9/5*c+32;
	printf("The temperature in Kelvin is: %d \nand the temperature in Fahrenheit is: %d",k,f);
}

/*
[cse1196@sel-25 A1]$ gcc 12-temp.c -o t
[cse1196@sel-25 A1]$ ./t
Enter the value of temperature in Celsius:0
The temperature in Kelvin is: 273 
and the temperature in Fahrenheit is: 32
*/
