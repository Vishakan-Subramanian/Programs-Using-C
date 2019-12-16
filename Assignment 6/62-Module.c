/*7. 
Redo 2nd problem of A6 using files. (fread, fwrite). Read the input from file and write output to
 another file. */

/*2.
Modularize problem 1 using functions to read input, write output, find average, class
average for ‘n’ number of students. (Hint: Passing Array of structures to function)
*/

#include<stdio.h>

typedef struct{
	char name[30];
	int mark[20];
	float avg;
}student;

void input(student s[],int n,int m);
void output(student s[], int n);
void average(student s[], int n, int m);
float classavg(student s[],int n);
void fwriter(student s[],int n,int m);
void freader(int n,int m,float avg);

FILE *fp;

void main(){
	student s[100];
	int m,n;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	printf("Enter the number of subjects: ");
	scanf("%d",&m);
	input(s,n,m);
	average(s,n,m);
	//printf("\nThe Class Average is: %.2f.",classavg(s,n));
	//output(s,n);
	writefile(s,n,m);					//write file
	readfile(n,m,classavg(s,n));					//read file
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

void fwriter(student s[],int n,int m)
{
int i=0;
fp=fopen("Student.dat","wb");		//open file in binary write mode
if(fp==NULL)
	{
	printf("File does not exist");
	exit(1);
	}

for(i=0;i<n;i++)
	{
	fwrite(&s[i],sizeof(struct student),1,fp);	//writing to file
	}
fclose(fp);	
}


void freader(int n,int m,float avg)
{
student s[n];
int i=0;
fp=fopen("Student.dat","rb");			//open file in binary read mode
if(fp==NULL)
	{
	printf("File does not exist");
	exit(1);
	}
printf("\n\tName\t|\tAverage\n");
for(i=0;i<n;i++)
	{
	fread(&s[i],sizeof(struct student),1,fp);		//reading from file
	printf("\n\t%s\t|\t%.2f",s[i].name,s[i].avg);		
	}
printf("Class Average = %.2f\n",avg);
fclose(fp);
}


/*
[root@sel-25 196 CSE C]# gcc 62-Module.c -o m
[root@sel-25 196 CSE C]# ./m
Enter the number of students: 3
Enter the number of subjects: 3

Enter student details.
Enter Student Name: Harvey

Enter Student Marks: 100
100
100

Enter Student Name: Pearson

Enter Student Marks: 95
96
97

Enter Student Name: Louis

Enter Student Marks: 98
96
95

The Class Average is: 97.44.
        Name    |       Average

        Harvey  |       100.00
        Pearson |       96.00
        Louis   |       96.33

 */