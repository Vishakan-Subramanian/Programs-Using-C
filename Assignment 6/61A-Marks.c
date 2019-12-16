/* 1.
a.)Write a C program to generate the average mark of a student of 3 subjects using
structures. Design the structures with suitable members for the given problem.
 */
#include<stdio.h>
#include<string.h>
struct stumark{
	int s1;
	int s2;
	int s3;
	float avg;
	}student;

void main(){
	int i;
	char opt;
	pos1:
	printf("\nEnter the marks of the student:");
	printf("\nSubject 1: ");
	scanf("%d",&student.s1);
	printf("\nSubject 2: ");
	scanf("%d",&student.s2);
	printf("\nSubject 3: ");
	scanf("%d",&student.s3);	
	student.avg=(student.s1+student.s2+student.s3)/3;
	printf("\nStudent's average score is: %.2f.",student.avg);
	printf("\nDo you wish to find average for another student?(Y/N)");
	scanf("%s",&opt);
	if(opt=='Y'||opt=='y')
		goto pos1;
	}

/*
[root@sel-25 196 CSE C]# gcc 61-Marks.c -o m
[root@sel-25 196 CSE C]# ./m

Enter the marks of the student:
Subject 1: 40

Subject 2: 30

Subject 3: 20

Student's average score is: 30.00.
Do you wish to find average for another student?(Y/N)Y

Enter the marks of the student:
Subject 1: 10

Subject 2: 20

Subject 3: 30

Student's average score is: 20.00.
Do you wish to find average for another student?(Y/N)
N
*/
