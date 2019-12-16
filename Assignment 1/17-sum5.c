/* sum 4 */

#include<stdio.h>
void main(){
	int n,sum=0;
	char ch;
	printf("Version 5\n");
	pos1:
	printf("Enter a positive number N less than 100 to add.");
	scanf("%d",&n);
	if(n<0||n>100){
		printf("Invalid input.");
	}
	else{
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
}

/*
Version 5
Enter a positive number N less than 100 to add.10
Do you wish to continue? (Y/N) y
Enter a positive number N less than 100 to add.20
Do you wish to continue? (Y/N) n
The sum is: 30
*/
