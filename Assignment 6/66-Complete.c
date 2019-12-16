/*6.
Finally convert into a menu driven C program as
1. Read Input
2. Find Average
3. Class Average
4. Pass Percentage
5. Rank
6. Search By Name
7. Search By RegNo
8. Display Student Records
9. Exit
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student{
	int regno;
	char name[30];
	int mark[20];
	float avg;
	int res;
	int rank;
};

void input(struct student *s[100],int n,int m);
void output(struct student *s[100], int n);
void average(struct student *s[100], int n, int m);
float classavg(struct student *s[100],int n);
float overallpass(struct student *s[100], int n);
void passcalc(struct student *s[100], int n, int m);
void rank(struct student *s[100],int n);
void namefinder(struct student *s[100], int n);
void regfinder(struct student *s[100],int n);

void main(){
	struct student *s[100];
	int m,n,opt;
	char ch;
	do{
		printf("\nEnter an option.");
		printf("\nEnter 1 to give input\nEnter 2 to find average\nEnter 3 to find class average\nEnter 4 to find overall pass percentage\nEnter 5 to find rank\nEnter 6 to find student by name\nEnter 7 to find student by register number\nEnter 8 to display student records\nEnter 9 to exit\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
						printf("Enter the number of students: ");
						scanf("%d",&n);
						printf("Enter the number of subjects: ");
						scanf("%d",&m);
						input(s,m,n);
						break;
			case 2:
					average(s,n,m);
					printf("\nAverage has been found. Press 8 to view details.");
					break;
			case 3:
					printf("\nThe Class Average is: %.2f.",classavg(s,n));
					break;
			case 4:
					passcalc(s,n,m);
					printf("\nThe Overall Pass Percentage is :%.2f",overallpass(s,n));
					break;
			case 5:
					rank(s,n);
					output(s,n);
					break;
			case 6:
					namefinder(s,n);
					break;
			case 7:
					regfinder(s,n);
					break;
			case 8:
					printf("\nStudent Details:");
					output(s,n);
					break;
			case 9:
					printf("\nThank you.");
					break;
			default:
					printf("Enter a valid option.");

		}
	}while(opt!=9);
}

void input(struct student *s[100],int n, int m){
	int i,j;
	
	printf("\nEnter student details.");
	for(i=0;i<n;i++){
		s[i] = (struct student *) malloc(sizeof(struct student));
		printf("\nEnter Student Register Number: ");
		scanf("%d",&((s[i])->regno));
		printf("\nEnter Student Name: ");
		scanf("%s",((s[i])->name));
		printf("\nEnter Student Marks: ");
		for(j=0;j<m;j++)
			scanf("%d",&((s[i])->mark[j]));
	}
}

void average(struct student *s[100], int n, int m){
	int i,j;

	for(i=0;i<n;i++)
	{
		s[i]->avg=0;
		
		for(j=0;j<m;j++)
			s[i]->avg+=s[i]->mark[j];
		
		s[i]->avg/=m;
	}
}

float classavg(struct student *s[100], int n){
	float a=0;
	for(int i=0;i<n;i++)
		a+=s[i]->avg;
	return(a/n);
}

void output(struct student *s[100],int n){
		printf("\n\tReg.No.\t|\tName\t\t|\tAverage\t|\tRank\n");
		for(int i=0;i<n;i++)
			printf("\n\t%d\t|\t%s\t|\t%.2f\t|\t%d",s[i]->regno,s[i]->name,s[i]->avg,s[i]->rank);
}

void passcalc(struct student *s[100],int n, int m){
	int i,j;
	for(i=0;i<n;i++){
		s[i]->res=1;
		for(j=0;j<m;j++)
			if(s[i]->mark[j]<40){
				s[i]->res=0;
				break;
			}
	}
}

float overallpass(struct student *s[100],int n){
	int i=0;
	float op;
	for(i=0;i<n;i++){
		op+=s[i]->res;
	}
	op=op*100;
	op/=n;
	return op;
}

void rank(struct student *s[100], int n){
	int i,j;
	for(i=0;i<n;i++){
		s[i]->rank=1;
		for(j=0;j<n;j++){
			if(s[i]->avg<s[j]->avg)
				s[i]->rank++;
		}
	}
}

void namefinder(struct student *s[100],int n){
			int i,no=0;
			char name[30];
			printf("\nEnter Name: ");
			scanf("%s",name);
			for(i=0;i<n;i++){
				if(strcmp(name,s[i]->name)==0){
					printf("\nStudent Details: ");
					printf("\n\tReg.No.\t|\tAverage\t|\tRank\n");
					printf("\n\t%d\t|\t%.2f\t|\t%d",s[i]->regno,s[i]->avg,s[i]->rank);	
					no=1;
				}
			}
			if(no==0)
				printf("\nStudent not found.");
}

void regfinder(struct student *s[100],int n){
			int i,no,chk=0;
			printf("\nEnter Register Number: ");
			scanf("%d",&no);
			for(i=0;i<n;i++){
				if(no==s[i]->regno){
					printf("\nStudent Details: ");
					printf("\n\tName\t\t|\tAverage\t|\tRank\n");
					printf("\n\t%s\t|\t%.2f\t|\t%d",s[i]->name,s[i]->avg,s[i]->rank);
					chk=1;
				}
			}
			if(chk==0)
				printf("\nStudent not found.");

}
/*
[root@sel-25 196 CSE C]# gcc 64B-Rank.c -o r1
[root@sel-25 196 CSE C]# ./r1

Enter an option.
Enter 1 to give input
Enter 2 to find average
Enter 3 to find class average
Enter 4 to find overall pass percentage
Enter 5 to find rank
Enter 6 to find student by name
Enter 7 to find student by register number
Enter 8 to display student records
Enter 9 to exit
1
Enter the number of students: 3
Enter the number of subjects: 3

Enter student details.
Enter Student Register Number: 131

Enter Student Name: Shashanka

Enter Student Marks: 90
98
97

Enter Student Register Number: 132

Enter Student Name: Siddharth

Enter Student Marks: 99
99
100

Enter Student Register Number: 133

Enter Student Name: Vishakan

Enter Student Marks: 98
97
96

Enter an option.
Enter 1 to give input
Enter 2 to find average
Enter 3 to find class average
Enter 4 to find overall pass percentage
Enter 5 to find rank
Enter 6 to find student by name
Enter 7 to find student by register number
Enter 8 to display student records
Enter 9 to exit
2

Average has been found. Press 8 to view details.
Enter an option.
Enter 1 to give input
Enter 2 to find average
Enter 3 to find class average
Enter 4 to find overall pass percentage
Enter 5 to find rank
Enter 6 to find student by name
Enter 7 to find student by register number
Enter 8 to display student records
Enter 9 to exit
3

The Class Average is: 97.11.
Enter an option.
Enter 1 to give input
Enter 2 to find average
Enter 3 to find class average
Enter 4 to find overall pass percentage
Enter 5 to find rank
Enter 6 to find student by name
Enter 7 to find student by register number
Enter 8 to display student records
Enter 9 to exit
4

The Overall Pass Percentage is :100.00
Enter an option.
Enter 1 to give input
Enter 2 to find average
Enter 3 to find class average
Enter 4 to find overall pass percentage
Enter 5 to find rank
Enter 6 to find student by name
Enter 7 to find student by register number
Enter 8 to display student records
Enter 9 to exit
5

        Reg.No. |       Name            |       Average |       Rank

        131     |       Shashanka       |       95.00   |       3
        132     |       Siddharth       |       99.33   |       1
        133     |       Vishakan        |       97.00   |       2
Enter an option.
Enter 1 to give input
Enter 2 to find average
Enter 3 to find class average
Enter 4 to find overall pass percentage
Enter 5 to find rank
Enter 6 to find student by name
Enter 7 to find student by register number
Enter 8 to display student records
Enter 9 to exit
6

Enter Name: Shashanka

Student Details:
        Reg.No. |       Average |       Rank

        131     |       95.00   |       3
Enter an option.
Enter 1 to give input
Enter 2 to find average
Enter 3 to find class average
Enter 4 to find overall pass percentage
Enter 5 to find rank
Enter 6 to find student by name
Enter 7 to find student by register number
Enter 8 to display student records
Enter 9 to exit
7

Enter Register Number: 133

Student Details:
        Name            |       Average |       Rank

        Vishakan        |       97.00   |       2
Enter an option.
Enter 1 to give input
Enter 2 to find average
Enter 3 to find class average
Enter 4 to find overall pass percentage
Enter 5 to find rank
Enter 6 to find student by name
Enter 7 to find student by register number
Enter 8 to display student records
Enter 9 to exit
8

Student Details:
        Reg.No. |       Name            |       Average |       Rank

        131     |       Shashanka       |       95.00   |       3
        132     |       Siddharth       |       99.33   |       1
        133     |       Vishakan        |       97.00   |       2
Enter an option.
Enter 1 to give input
Enter 2 to find average
Enter 3 to find class average
Enter 4 to find overall pass percentage
Enter 5 to find rank
Enter 6 to find student by name
Enter 7 to find student by register number
Enter 8 to display student records
Enter 9 to exit
9

Thank you.
 */