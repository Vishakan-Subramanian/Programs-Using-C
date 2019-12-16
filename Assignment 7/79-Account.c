/*9. 
Count the number of account holders whose balance is less than the minimum balance and
 display the same using sequential access file. (Hint: Use structure to represent the account) 
*/

#include<stdio.h>
#include<stdlib.h>

struct record{
	char name[30];
	int acno;
	float bal;
};

void input(struct record r[],int n);
void fwriter(struct record r[],int n);
void freader(int n,float min);

FILE *fp;

void main(){
		struct record r[100];
		int n;
		float min;
		printf("\nEnter the no. of account holders: ");
		scanf("%d",&n);
		input(r,n);
		fwriter(r,n);
		printf("\nEnter the minimum balance amount: ");
		scanf("%f",&min);
		freader(n,min);

}

void input(struct record r[],int n){
	int i,j;
	printf("\nEnter Customers' details.");
	for(i=0;i<n;i++){
		printf("\nCustomer %d:",(i+1));
		printf("\nEnter Customer Name: ");
		scanf("%s",r[i].name);
		printf("\nEnter Customer ID: ");
		scanf("%d",&r[i].acno);
		printf("\nEnter Customer Balance: ");
		scanf("%f",&r[i].bal);
	}
}

void fwriter(struct record r[],int n){
	int i=0;
	fp=fopen("Records.dat","wb");		//open file in binary write mode
	if(fp==NULL){
		printf("File does not exist");
		exit(1);
	}

	for(i=0;i<n;i++){
		fwrite(&r[i],sizeof(struct record),1,fp);	//writing to file
	}
fclose(fp);	
}

void freader(int n,float min)
{
struct record r[100];
int i=0,count=0;
fp=fopen("Records.dat","rb");			//open file in binary read mode
if(fp==NULL)
	{
	printf("File does not exist");
	exit(1);
	}
for(i=0;i<n;i++)
	{
	fread(&r[i],sizeof(struct record),1,fp);		//reading from file
	if(r[i].bal<min)
		count++;		//checking if balance is lesser than minimum requirement
	}
printf("\nNo. of people with balance less than minimum balance are: %d\n",count);
fclose(fp);
}

/*
[root@sel-25 196 CSE C]# gcc 79-Account.c -o a
[root@sel-25 196 CSE C]# ./a

Enter the no. of account holders: 4

Enter Customers' details.
Customer 1:
Enter Customer Name: Harry

Enter Customer ID: 1

Enter Customer Balance: 1000

Customer 2:
Enter Customer Name: Donald

Enter Customer ID: 2

Enter Customer Balance: 2000

Customer 3:
Enter Customer Name: Truman

Enter Customer ID: 3

Enter Customer Balance: 3000

Customer 4:
Enter Customer Name: Washington

Enter Customer ID: 4

Enter Customer Balance: 5000

Enter the minimum balance amount: 4000

No. of people with balance less than minimum balance are: 3

*/