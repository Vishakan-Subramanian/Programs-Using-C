//to check whether a number is odd or even.
#include <stdio.h>
void main()
{
	int num,rem;
	printf("Enter a number: ");
	scanf("%d",&num);
	rem=num%2;
	if(rem==1)
	{
	printf("Number is odd.");
	}
	else
	{
	printf("Number is even.");
	}
}

/*
[cse1196@sel-25 A1]$ gcc 11-oddeven.c -o o
[cse1196@sel-25 A1]$ ./o
Enter a number: 5
Number is odd.
*/
