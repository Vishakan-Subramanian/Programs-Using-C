/* 1.
c) Modify problem 1b in such a way to incorporate for ‘n’ number of students. (Hint:
Array of structures)
 */
#include<stdio.h>
#include<string.h>
struct stumark{
	int s[20];
	float avg;
	}student[100];

void main(){
	int i,j,nstu,ns;
	char opt;
	pos1:
	printf("\nEnter the number of students: ");
	scanf("%d",&nstu);
	
	printf("\nEnter the number of subjects: ");
	scanf("%d",&ns);
	for(j=0;j<nstu;j++){
		printf("\nEnter the marks of the student %d:",j+1);
		for(i=0;i<ns;i++){
			printf("\nSubject %d: ",(i+1));
			scanf("%d",&student[j].s[i]);
			student[j].avg+=student[j].s[i];
			}
		student[j].avg/=ns;
		printf("\nStudent's average score is: %.2f.",student[j].avg);
		}
	printf("\nDo you wish to find average for another set of students?(Y/N)");
	scanf("%s",&opt);
	if(opt=='Y'||opt=='y')
		goto pos1;
	}

/*
[root@sel-25 196 CSE C]# gcc 61C-Marks.c -o m3
[root@sel-25 196 CSE C]# ./m3

Enter the number of students: 5

Enter the number of subjects: 3

Enter the marks of the student 1:
Subject 1: 20

Subject 2: 30

Subject 3: 40

Student's average score is: 30.00.
Enter the marks of the student 2:
Subject 1: 40

Subject 2: 50

Subject 3: 60

Student's average score is: 50.00.
Enter the marks of the student 3:
Subject 1: 91

Subject 2: 92

Subject 3: 93

Student's average score is: 92.00.
Enter the marks of the student 4:
Subject 1: 79

Subject 2: 79

Subject 3: 79

Student's average score is: 79.00.
Enter the marks of the student 5:
Subject 1: 81

Subject 2: 87

Subject 3: 67

Student's average score is: 78.33.
Do you wish to find average for another set of students?(Y/N)N
*/
