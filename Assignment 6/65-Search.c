/*5.
Write a function to search a record by name or regno. */
/*4.b) 
Modify 4a in such a way to skip ranks if the same rank is shared by more than one
student. Eg: If 3 student shares rank 1 then 4th student should be given rank 4.*/

#include<stdio.h>
#include<string.h>

typedef struct{
	int regno;
	char name[30];
	int mark[20];
	float avg;
	int res;
	int rank;
}student;

void input(student s[],int n,int m);
void output(student s[], int n);
void average(student s[], int n, int m);
float classavg(student s[],int n);
float overallpass(student s[], int n);
void passcalc(student s[], int n, int m);
void rank(student s[],int n);
void namefinder(student s[], int n);
void regfinder(student s[],int n);

void main(){
	student s[100];
	int m,n;
	char ch;
	int opt;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	printf("Enter the number of subjects: ");
	scanf("%d",&m);
	input(s,n,m);
	average(s,n,m);
	passcalc(s,n,m);
	rank(s,n);
	printf("\nThe Class Average is: %.2f.",classavg(s,n));
	printf("\nThe Overall Pass Percentage is :%.2f",overallpass(s,n));
	output(s,n);
	pos1:
	printf("\nDo you wish to find a particular record?(Y/N)");
	scanf("%s",&ch);
	if(ch=='Y'||ch=='y'){
		printf("\nPress 1 to find with Student Register Number\nPress 2 to find with Student Name.");
		scanf("%d",&opt);
		if(opt==1)
			regfinder(s,n);
		else if(opt==2)
			namefinder(s,n);
		else
			printf("\nInvalid option.");
		goto pos1;
	}
}

void input(student s[],int n, int m){
	int i,j;
	printf("\nEnter student details.");
	for(i=0;i<n;i++){
		printf("\nEnter Student Register Number: ");
		scanf("%d",&s[i].regno);
		printf("\nEnter Student Name: ");
		scanf("%s",s[i].name);
		printf("\nEnter Student Marks: ");
		for(j=0;j<m;j++)
			scanf("%d",&s[i].mark[j]);
	}
}

void average(student s[], int n, int m){
	int i,j;

	for(i=0;i<n;i++)
	{
		s[i].avg=0;
		
		for(j=0;j<m;j++)
			s[i].avg+=s[i].mark[j];
		
		s[i].avg/=m;
	}
}

float classavg(student s[], int n){
	float a=0;
	for(int i=0;i<n;i++)
		a+=s[i].avg;
	return(a/n);
}

void output(student s[],int n){
		printf("\n\tReg.No.\t|\tName\t\t|\tAverage\t|\tRank\n");
		for(int i=0;i<n;i++)
			printf("\n\t%d\t|\t%s\t\t|\t%.2f\t|\t%d",s[i].regno,s[i].name,s[i].avg,s[i].rank);
}

void passcalc(student s[],int n, int m){
	int i,j;
	for(i=0;i<n;i++){
		s[i].res=1;
		for(j=0;j<m;j++)
			if(s[i].mark[j]<40){
				s[i].res=0;
				break;
			}
	}
}

float overallpass(student s[],int n){
	int i=0;
	float op;
	for(i=0;i<n;i++){
		op+=s[i].res;
	}
	op=op*100;
	op/=n;
	return op;
}

void rank(student s[], int n){
	int i,j;
	for(i=0;i<n;i++){
		s[i].rank=1;
		for(j=0;j<n;j++){
			if(s[i].avg<s[j].avg)
				s[i].rank++;
		}
	}
}

void namefinder(student s[],int n){
			int i,no=0;
			char name[30];
			printf("\nEnter Name: ");
			scanf("%s",name);
			for(i=0;i<n;i++){
				if(strcmp(name,s[i].name)==0){
					printf("\nStudent Details: ");
					printf("\n\tReg.No.\t|\tAverage\t|\tRank\n");
					printf("\n\t%d\t|\t%.2f\t|\t%d",s[i].regno,s[i].avg,s[i].rank);	
					no=1;
				}
			}
			if(no==0)
				printf("\nStudent not found.");
}

void regfinder(student s[],int n){
			int i,no,chk=0;
			printf("\nEnter Register Number: ");
			scanf("%d",&no);
			for(i=0;i<n;i++){
				if(no==s[i].regno){
					printf("\nStudent Details: ");
					printf("\n\tName\t\t|\tAverage\t|\tRank\n");
					printf("\n\t%s\t|\t%.2f\t|\t%d",s[i].name,s[i].avg,s[i].rank);
					chk=1;
				}
			}
			if(chk==0)
				printf("\nStudent not found.");

}
/*
[root@sel-25 196 CSE C]# gcc 64B-Rank.c -o r1
[root@sel-25 196 CSE C]# ./r1
Enter the number of students: 3
Enter the number of subjects: 3

Enter student details.
Enter Student Register Number: 131

Enter Student Name: Sharan

Enter Student Marks: 90
95
94

Enter Student Register Number: 132

Enter Student Name: Siddharth

Enter Student Marks: 99
99
100

Enter Student Register Number: 133

Enter Student Name: Shashanka

Enter Student Marks: 89
97
95

The Class Average is: 95.33.
The Overall Pass Percentage is :100.00
	Reg.No.	|	Name		|	Average	|	Rank

	131	|	Sharan			|	93.00	|	3
	132	|	Siddharth		|	99.33	|	1
	133	|	Shashanka		|	93.67	|	2
Do you wish to find a particular record?(Y/N)y

Press 1 to find with Student Register Number
Press 2 to find with Student Name.1

Enter Register Number: 131

Student Details: 
	Name		|	Average	|	Rank

	Sharan		|	93.00	|	3
Do you wish to find a particular record?(Y/N)y

Press 1 to find with Student Register Number
Press 2 to find with Student Name.2

Enter Name: Shashanka

Student Details: 
	Reg.No.	|	Average	|	Rank

	133		|	93.67	|	2
Do you wish to find a particular record?(Y/N)n



 */