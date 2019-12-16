#include<stdio.h>
float Withdraw(float bal);
float Deposit(float bal);
int warn=0;
void main(){
	float bal=0;
	int c=0;
	int x=0;
	printf("Transactions\n");
	printf("Enter your balance amount currently existing: ");
	scanf("%f",&bal);
	do{
		pos1:
		printf("\nDo you wish to transact?\nEnter 1 for Deposit. 2 for Withdrawal. 3 to exit.");
		scanf("%d",&c);
		if(c==1){
			bal=Deposit(bal);
		}
		else if(c==2){
			bal=Withdraw(bal);
		}
		else if(c==3){
			x=1;
		}
		else{
			printf("Invalid option.\n");
			goto pos1;
		}
	}while(x==0);
}
float Deposit(float bal){
	float dep=0;
	printf("\nEnter the amount you wish to deposit: ");
	scanf("%f",&dep);
	bal=bal+dep;
	printf("\nThe remanining balance is: %f",bal);
	if(bal>=0){
		warn=0;
	}
	return bal;
}
float Withdraw(float bal){
	float wd=0;
	printf("\nEnter the amount you wish to withdraw: ");
	scanf("%f",&wd);
	if((bal-wd)<0){
		warn++;
	}
	if(warn>=4){
		printf("\nInsufficient balance. Please deposit some money to continue transacting.");
		return bal;
	}
	else{
		bal=bal-wd;
		if(bal>=0){
			printf("\nThe remaining balance is: %f",bal);
		}
		return bal;
	}
}  