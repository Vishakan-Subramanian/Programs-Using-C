/* Sum of N numbers */

#include<stdio.h>
void main(){
	float m,n,r=0;
	int ch;
	printf("Calculator\n");
	printf("Enter a number.\n");
	scanf("%f",&m);
	pos1:
	printf("Enter an operation to perform. (1 for addition, 2 for subtraction, 3 for multiplication, 4 for division, 5 for squaring)");
	scanf(" %d",&ch);
	switch(ch){
		case 1:  //addition
			printf("Enter another number.");  
			scanf("%f",&n);
			r=m+n;
			break;


		case 2:    //subtraction
			printf("Enter another number.");
			scanf("%f",&n);
			r=m-n;
			break;

		case 3:    //multiplication
			printf("Enter another number.");
			scanf("%f",&n);
			r=m*n;
			break;

		case 4:     //division
			printf("Enter another number.");
			scanf("%f",&n);
			r=m/n;
			break;

		case 5:     //square
			r=m*m;
			break;

		default:  //invalid
			printf("Invalid operation.");
			goto pos1;
			break;


	}
	printf("Result is: %f",r);

}

/*
Calculator
Enter a number.
10
Enter an operation to perform. (1 for addition, 2 for subtraction, 3 for multipl
ication, 4 for division, 5 for squaring)3
Enter another number.20
Result is: 200.000000
Calculator
Enter a number.
10
Enter an operation to perform. (1 for addition, 2 for subtraction, 3 for multipl
ication, 4 for division, 5 for squaring)5
Result is: 100.000000
*/
