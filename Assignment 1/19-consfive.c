/*consecutive 5s*/

#include<stdio.h>
void main(){
	printf("Checking for 3 consecutive 5s.\n");
	printf("Enter any number.");
	int m,n,k,d,flag=0,b,i=1,chk;
	scanf("%d",&n);
	m=n;
	while(n>0){
		k++;
		n/=10;
	}
	while(m>0){
		d=m%10;
		if(d==5){
			flag++;
			b++;
		}
		if(d!=5){
			if(b==1||b==2||b==0){   //consecutive check
				flag=0;
				b=0;	
			}		
		}
		m/=10;
		i++;
	}
	if(flag>=3){
		printf("Result:YES");

		}
	else{
		printf("Result:NO");
		}

}

/*
Checking for 3 consecutive 5s.
Enter any number.755557
Result:YES
Checking for 3 consecutive 5s.
Enter any number.7557
Result:NO
*/
