//to check whether a number is odd or even.
#include <stdio.h>
void main()
{
int num,rem;
printf("Enter a number: ");
scanf("%d",&num);
    (num & 1 && printf("It is an odd number."))|| printf("It is an even number.");  /* bitwise operator */

}

/*
Enter a number: 10
It is an even number.
Enter a number: 9
It is odd even number.
*/
