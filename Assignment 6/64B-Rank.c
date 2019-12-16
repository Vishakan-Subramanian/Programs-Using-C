/*4.b) 
Modify 4a in such a way to skip ranks if the same rank is shared by more than one
student. Eg: If 3 student shares rank 1 then 4th student should be given rank 4.*/

#include<stdio.h>

typedef struct{
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

void main(){
	student s[100];
	int m,n;
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
}

void input(student s[],int n, int m){
	int i,j;
	printf("\nEnter student details.");
	for(i=0;i<n;i++){
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
		printf("\n\tName\t\t|\tAverage\t|\tRank\n");
		for(int i=0;i<n;i++)
			printf("\n\t%s\t\t|\t%.2f\t|\t%d",s[i].name,s[i].avg,s[i].rank);
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
/*
[root@sel-25 196 CSE C]# gcc 64B-Rank.c -o r1
[root@sel-25 196 CSE C]# ./r1
Enter the number of students: 5
Enter the number of subjects: 3

Enter student details.
Enter Student Name: Amudhan

Enter Student Marks: 90
90
90

Enter Student Name: Harish

Enter Student Marks: 97
97
96

Enter Student Name: Kadhiresan

Enter Student Marks: 90
90
90

Enter Student Name: Harsha

Enter Student Marks: 87
68
79

Enter Student Name: Sanjith

Enter Student Marks: 97
97
96

The Class Average is: 90.27.
The Overall Pass Percentage is :100.00
        Name    		|       Average |       Rank

        Amudhan 		|       90.00   |       3
        Harish 			|       96.67   |       1
        Kadhiresan      |       90.00   |       3
        Harsha  		|       78.00   |       5
        Sanjith 		|       96.67   |       1

 */