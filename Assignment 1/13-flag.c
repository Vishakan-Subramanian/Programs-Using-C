//to flag based on whether a number is odd or even.
#include <stdio.h>
void main()
{
	int num,rem,flag;
	printf("Enter a number: ");
	scanf("%d",&num);
	rem=num%2;
	if(rem==1)
	{
	flag=1;
	}
	else
	{
	flag=0;
	}
}

/*
[cse1196@sel-25 A1]$ gcc 13-flag.c -o f
[cse1196@sel-25 A1]$ ./f
Enter a number: 10
*/
