/*
Implement Example program 11.22 (Adding two tables of numbers) (Page 11.26) of text book
(Byron Gottfried). Modify the program creating another version so that each element in the
table c is the larger of the corresponding elements in tables a and b (rather than the sum of the
corresponding elements in a and b).
a. Represent each table (each array) as a pointer to a group one dimensional arrays, as in
example 11.22. Use pointer notation to access the individual table elements.
b. Represent each table (each array) as a one-dimensional array of pointers and solve the
problem.
*/
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int *a[30], *b[30], *c[30];
	int i, j, m, n,choice;
	
	printf("\nMatrix Operations.");
	printf("\nEnter the number of rows and columns of the 2 matrices:\n");
	scanf(" %d %d", &m, &n);
	
	//memory allocation for the matrices
	for(i=0; i<m; i++)
	{ //allocating memory spaces for each column
		a[i] = (int *) malloc(sizeof(int) * n);
		b[i] = (int *) malloc(sizeof(int) * n);
		c[i] = (int *) malloc(sizeof(int) * n);
	}
	
	printf("\nEnter matrix 1 elements:\n");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf(" %d", *(a+i)+j);
	
	
	printf("\nEnter matrix 2 elements:\n");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf(" %d", *(b+i)+j);
	repeat:
	printf("\nEnter the operation to be performed:\n1 for Addition\n2 for Maximum of the two matrices\n");
	scanf("%d",&choice);
	if(choice==1){
		//to add 2 matrices
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
				*(*(c+i) + j) = *(*(a+i)+j) + *(*(b+i)+j);
	
	
	printf("\nSum of the two matrices is:\n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
			printf("%d\t", *(*(c+i) + j));
		printf("\n");
	}
	}
	else if(choice==2){
		//to find the maximum of 2 corresponding elements of 2 matrices.
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(*(*(a+i)+j)>*(*(b+i)+j))
					*(*(c+i)+j)=*(*(a+i)+j);
				else
					*(*(c+i)+j)=*(*(b+i)+j);
	printf("\nMaximum elements of the two matrices are:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			printf("%d\t", *(*(c+i) + j));
		printf("\n");
	}
	}
	
	else{
		printf("\nInvalid input.");
		goto repeat;
	}
    	
	
}

/*
[root@sel-25 196 CSE C]# ./m

Matrix Operations.
Enter the number of rows and columns of the 2 matrices:
2
2

Enter matrix 1 elements:
2
4
6
8

Enter matrix 2 elements:
1
3
5
7

Enter the operation to be performed:
1 for Addition
2 for Maximum of the two matrices
1

Sum of the two matrices is:
3       7
11      15

[root@sel-25 196 CSE C]# ./m

Matrix Operations.
Enter the number of rows and columns of the 2 matrices:
2
2

Enter matrix 1 elements:
2
4
6
8

Enter matrix 2 elements:
1
3
5
7

Enter the operation to be performed:
1 for Addition
2 for Maximum of the two matrices
2

Maximum elements of the two matrices are:
2       4
6       8
*/