/* 3. Given an array of integers, push all the zero’s of a given array to the end of the array. Write a
program in C that implements the function pushZerosToEnd(int arr[], int n). */

#include<stdio.h>
void pushZerosToEnd(int a[],int n);
void main(){
	int n=0;
	printf("Array Zero Sorter \n");
	printf("Enter the number of terms in the array.");
	scanf("%d",&n);
	int a[n],i;
	printf("Enter the terms, separated by spaces:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);	
	}
	printf("The initial array is:\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);	
	}
	pushZerosToEnd(a,n);	
}
void pushZerosToEnd(int a[],int n){
	int i=0,j=n-1,temp=0;
	for(i=0;i<n;i++){
		if(a[i]==0){
			for(j=i;j<=n-1;j++){
				if(a[j]!=0){
					a[i]=a[j];
					a[j]=0;
					break;
				}	
			}
				
		}	

	}
	printf("\nThe final array is:\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}

/*
[root@sel-25 196 CSE C]# ./zp
Array Zero Sorter 
Enter the number of terms in the array.8
Enter the terms, separated by spaces:
5 3 0 1 3 0 8 0
The initial array is:
5 3 0 1 3 0 8 0 
The final array is:
5 3 1 3 8 0 0 0 
*/
