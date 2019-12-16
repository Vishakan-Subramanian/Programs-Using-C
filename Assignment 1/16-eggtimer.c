#include<stdio.h>
void main(){
	printf("Egg Timer\n");
	pos1:
	printf("Enter a number between 3 and 10.");
	int s,j,i,n=0;
	scanf("%d",&n);
	if(n>10||n<0){
		goto pos1;
	}
	else{
		for(i=n;i>1;i--){
			j=i;
			s=n-i;
			while(j>0){
				while(s!=0){
					printf(" ");
					s--;
				}
				if(j>i/2){
					printf("*-");
					j--;
				}
				else if(j==i/2){
					printf("*");
					j--;
				}
				else{
					printf("-*");
					j--;
				}
			}
			printf("\n");
		}
		s=n-1;
		while(s!=0){
			printf(" ");
			s--;
			}
		printf("*");
		printf("\n");
		for(i=2;i<=n;i++){
			j=i;
			s=n-i;
			while(j>0){
				while(s!=0){
					printf(" ");
					s--;
				}
				if(j>i/2){
					printf("*-");
					j--;
				}
				else if(j==i/2){
					printf("*");
					j--;
				}
				else{
					printf("-*");
					j--;
				}
			}
			printf("\n");
		}
	
	}
}


/*
Egg Timer
Enter a number between 3 and 10.5
*-*-*-*-*
 *-*-*-*
  *-*-*
   *-*
    *
   *-*
  *-*-*
 *-*-*-*
*-*-*-*-*
*/
