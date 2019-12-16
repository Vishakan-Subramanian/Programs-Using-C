/* 1.
b)Modify problem 1a in such a way to incorporate for ‘n’ number of subjects. (Hint:
Array as structure members)
 */
#include<stdio.h>
#include<string.h>
struct stumark{
	int s[20];
	float avg;
	}student;

void main(){
	int i,n;
	char opt;
	pos1:
	printf("\nEnter the number of subjects: ");
	scanf("%d",&n);
	printf("\nEnter the marks of the student:");
	for(i=0;i<n;i++){
		printf("\nSubject %d: ",(i+1));
		scanf("%d",&student.s[i]);
		student.avg+=student.s[i];
	}	
	student.avg/=n;
	printf("\nStudent's average score is: %.2f.",student.avg);
	printf("\nDo you wish to find average for another student?(Y/N)");
	scanf("%s",&opt);
	if(opt=='Y'||opt=='y')
		goto pos1;
	}

/*
[root@sel-25 196 CSE C]# gcc 61B-Marks.c -o m2
[root@sel-25 196 CSE C]# ./m2

Enter the number of subjects: 5

Enter the marks of the student:
Subject 1: 10

Subject 2: 20

Subject 3: 30

Subject 4: 40

Subject 5: 50

Student's average score is: 30.00.
Do you wish to find average for another student?(Y/N)N
*/
