/* sum 3 */

#include<stdio.h>
void main(){
	int n,sum=0;
	char ch;
	printf("Version 3\n");
	pos1:
	printf("Enter a number N to add.");
	scanf(" %d",&n);
	sum=sum+n;
	pos2:
	printf("Do you wish to continue? (Y/N) ");
	scanf(" %c",&ch);
	switch(ch){
		case 'Y':
		case 'y':
			goto pos1;
			break;
		case 'N':	
		case 'n':
			printf("The sum is: %d",sum);
			break;
		default:
			printf("Invalid input.");
			goto pos2;	
	}
}

/*
Version 3
Enter a number N to add.10
Do you wish to continue? (Y/N) y
Enter a number N to add.30
Do you wish to continue? (Y/N) y
Enter a number N to add.20
Do you wish to continue? (Y/N) n
The sum is: 60
*/
