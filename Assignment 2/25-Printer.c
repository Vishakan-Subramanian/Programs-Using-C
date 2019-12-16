/* Write a recursive function that reads N and prints from N to 0. 
Input
Output
10
9876543210 */

#include<stdio.h>
void Printer(int n);
void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	Printer(n);
	}
void Printer(int n){
	/* To print all numbers from N to 0 */
	if(n>=0){
		printf("%d",n);
		n--;
		Printer(n);
		}
}

/* 
[root@sel-25 Desktop]# gcc 25-Printer.c -o pr
[root@sel-25 Desktop]# ./pr
Enter a number: 10
109876543210
*/
