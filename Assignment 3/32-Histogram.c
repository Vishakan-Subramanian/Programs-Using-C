/* 2. Write a program that accepts a set of digits (0 to 9) as input and prints a vertical histogram
representing the occurrences of each digit. Test your program with the set of 13 digits: 1, 7,
2 ,9 ,6, 7, 1, 3, 7, 5, 7, 9, 0 */

#include<stdio.h>
void main(){
	int n;
	printf("Histogram \n");
	printf("Enter the no. of terms: ");
	scanf("%d",&n);
	int a[n],i=0,m=0,b[]={0,0,0,0,0,0,0,0,0,0};
	printf("Enter terms between 0-9, separated by spaces: \n");
	for(i=0;i<n;i++){  //accepting input	
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){ //finding no. of times each term has occurred
		for(m=0;m<=9;m++){
			if(a[i]==m)
				b[m]+=1;
		}
	}
	int max=b[0];
	for(i=1;i<=9;i++){  //finding the highest occuring value
		if(b[i]>max)
			max=b[i];
	}
	for(i=max;i>=0;i--){ //printing a vertical histogram
		if(i!=0){
			for(m=0;m<=9;m++){
				if(b[m]>=i)
					printf("*");
				else
					printf(" ");	
			}
		}
		else
			printf("0123456789");
		printf("\n");	
	}
}

/*
[root@sel-25 196 CSE C]# ./h
Histogram 
Enter the no. of terms: 10
Enter a term between 0-9, separated by spaces: 
1 2 3 1 2 3 4 5 1 4   
 *        
 ****     
 *****    
0123456789
*/
