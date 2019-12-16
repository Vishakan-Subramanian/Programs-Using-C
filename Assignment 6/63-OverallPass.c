/*3. 
Write function for finding pass percentage of the overall class.*/

#include<stdio.h>

typedef struct{
	char name[30];
	int mark[20];
	float avg;
	int res;
}student;

void input(student s[],int n,int m);
void output(student s[], int n);
void average(student s[], int n, int m);
float classavg(student s[],int n);
float overallpass(student s[], int n);
void passcalc(student s[], int n, int m);

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
		printf("\n\tName\t|\tAverage\n");
		for(int i=0;i<n;i++)
			printf("\n\t%s\t|\t%.2f",s[i].name,s[i].avg);
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
/*
[root@sel-25 196 CSE C]# gcc 63-OverallPass.c -o o
[root@sel-25 196 CSE C]# ./o
Enter the number of students: 3
Enter the number of subjects: 3

Enter student details.
Enter Student Name: Maran

Enter Student Marks: 40
30
20

Enter Student Name: Nidhi

Enter Student Marks: 90

98
98

Enter Student Name: Harish

Enter Student Marks: 50
60
50

The Class Average is: 59.56.
The Overall Pass Percentage is :66.67
        Name    |       Average

        Maran   |       30.00
        Nidhi   |       95.33
        Harish  |       53.33
 */