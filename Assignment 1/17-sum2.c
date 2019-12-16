/* sum 2 */

#include<stdio.h>
void main(){
	int n,sum=0;
	printf("Version 2\n");
	pos1:
	printf("Enter a number N to add. Enter -999 to stop.");
	scanf("%d",&n);
	if(n==-999){
		printf("The sum is: %d",sum);
	}
	else{
		sum=sum+n;
		goto pos1;
	}

}

/*
Version 2
Enter a number N to add. Enter -999 to stop.10
Enter a number N to add. Enter -999 to stop.20
Enter a number N to add. Enter -999 to stop.40
Enter a number N to add. Enter -999 to stop.
-999
The sum is: 70
*/
