/*4.1 Marksheet Generator for a class of n students */
#include<stdio.h>
void main(){
	int n,j=0,k=0;
	printf("Marksheet Generator\n");
	printf("Enter the number of students in the class: ");
	scanf("%d",&n);
	char name[n][30];
	float mark[n][8];
	float c_avg;
	printf("\nEnter the names of the students (press Enter key after each name):\n");
	j=0;
	while(j<=n){  //getting the student names
		gets(name[j-1]);
		j++;
	}
	j=0;
	printf("\nEnter marks (separate each mark by a space): ");
	while(j<n){   //getting the student marks
		k=0;
		printf("\nMarks of Student %s: ",name[j]);
		while(k<=5){
			scanf("%f",&mark[j][k]);
			k++;
		}
		j++;
	}
	for(j=0;j<n;j++){  //to calculate class average and individual average
		mark[j][6]=0.15*(mark[j][0]+mark[j][1]+mark[j][2]+mark[j][3])+0.20*(mark[j][4]+mark[j][5]);
		c_avg+=mark[j][6];
	}
	c_avg/=n;
	for(j=0;j<n;j++) //deviation about class avg
		mark[j][7]=mark[j][6]-c_avg;
	printf("\nFinal Marksheet:\n");
	for(j=0;j<n;j++){  //printing the marksheet
		printf("\nClass Avg: %.2f  Name: ",c_avg);
		puts(name[j]);
		printf("Ind. Marks:");
		for(k=0;k<=5;k++){
			printf("%.2f  ",mark[j][k]);
		}
		printf("Ind. Avg: %.2f",mark[j][6]);
		printf("\nDeviation from CA: %.2f\n",mark[j][7]);
	}
	
		
		
	
}

/*
[root@sel-25 196 CSE C]# ./m
Marksheet Generator
Enter the number of students in the class: 14

Enter the names of the students (press Enter key after each name):
Adams
Brown
Davis
Fisher
Hamilton
Jones
Ludwig
Osborne
Prince
Richards
Smith
Thomas
Wolfe
Zorba

Enter marks (separate each mark by a space):
Marks of Student Adams: 45 80 80 95 55 75

Marks of Student Brown: 60 50 70 75 55 80

Marks of Student Davis: 40 30 10 45 60 55

Marks of Student Fisher: 0 5 5 0 10 5

Marks of Student Hamilton: 90 85 100 95 90 90

Marks of Student Jones: 95 90 80 95 85 80

Marks of Student Ludwig: 35 50 55 65 45 70

Marks of Student Osborne: 75 60 75 60 70 80

Marks of Student Prince: 85 75 60 85 90 100

Marks of Student Richards: 50 60 50 35 65 70

Marks of Student Smith: 70 60 75 70 55 75

Marks of Student Thomas: 10 25 35 20 30 10

Marks of Student Wolfe: 25 40 65 75 85 95

Marks of Student Zorba: 65 80 70 100 60 95

Final Marksheet:

Class Avg: 61.36  Name: Adams
Ind. Marks:45.00  80.00  80.00  95.00  55.00  75.00  Ind. Avg: 71.00
Deviation from CA: 9.64
Class Avg: 61.36  Name: Brown
Ind. Marks:60.00  50.00  70.00  75.00  55.00  80.00  Ind. Avg: 65.25
Deviation from CA: 3.89
Class Avg: 61.36  Name: Davis
Ind. Marks:40.00  30.00  10.00  45.00  60.00  55.00  Ind. Avg: 41.75
Deviation from CA: -19.61
Class Avg: 61.36  Name: Fisher
Ind. Marks:0.00  5.00  5.00  0.00  10.00  5.00  Ind. Avg: 4.50
Deviation from CA: -56.86
Class Avg: 61.36  Name: Hamilton
Ind. Marks:90.00  85.00  100.00  95.00  90.00  90.00  Ind. Avg: 91.50
Deviation from CA: 30.14
Class Avg: 61.36  Name: Jones
Ind. Marks:95.00  90.00  80.00  95.00  85.00  80.00  Ind. Avg: 87.00
Deviation from CA: 25.64
Class Avg: 61.36  Name: Ludwig
Ind. Marks:35.00  50.00  55.00  65.00  45.00  70.00  Ind. Avg: 53.75
Deviation from CA: -7.61
Class Avg: 61.36  Name: Osborne
Ind. Marks:75.00  60.00  75.00  60.00  70.00  80.00  Ind. Avg: 70.50
Deviation from CA: 9.14
Class Avg: 61.36  Name: Prince
Ind. Marks:85.00  75.00  60.00  85.00  90.00  100.00  Ind. Avg: 83.75
Deviation from CA: 22.39
Class Avg: 61.36  Name: Richards
Ind. Marks:50.00  60.00  50.00  35.00  65.00  70.00  Ind. Avg: 56.25
Deviation from CA: 5.11
Class Avg: 61.36  Name: Smith
Ind. Marks:70.00  60.00  75.00  70.00  55.00  75.00  Ind. Avg: 67.25
Deviation from CA: 5.89
Class Avg: 61.36  Name: Thomas
Ind. Marks:10.00  25.00  35.00  20.00  30.00  10.00  Ind. Avg: 21.50
Deviation from CA: -39.86
Class Avg: 61.36  Name: Wolfe
Ind. Marks:25.00  40.00  65.00  75.00  85.00  95.00  Ind. Avg: 66.75
Deviation from CA: 5.39
Class Avg: 61.36  Name: Zorba
Ind. Marks:65.00  80.00  70.00  100.00  60.00  95.00  Ind. Avg: 78.25
Deviation from CA: 16.89
*/