/*1.
Write a C program to read the text file input.txt  and display it on the console. */

#include<stdio.h>

int main(){
	FILE *ptr;
	char ch;
	printf("\nOpening File input.txt and printing its contents..."); 
	ptr=fopen("C:\\Users\\Vishakan\\Desktop\\input.txt","r"); ///opening file in R mode
	
	if(ptr==NULL){  //if file not found
		fclose(ptr);
		printf("\nSource File was not found.");
		return 0;
	}
	printf("\nContents: \n");
	while(!feof(ptr)){  //reading till end of file is reached
		ch=getc(ptr);
		printf("%c",ch);	//printing the char
	}

	fclose(ptr);
	return 0;
}
/*
C:\Users\Vishakan\Desktop>gcc 71-Read.c -o h

C:\Users\Vishakan\Desktop>h

Opening File input.txt and printing its contents...
Contents:
Hey
Welcome to C programming
This is a demo of files in C
Hope you liked it
For more demos, visit lms.ssn.edu.in 

C:\Users\Vishakan\Desktop>type input.txt
Hey
Welcome to C programming
This is a demo of files in C
Hope you liked it
For more demos, visit lms.ssn.edu.in
*/