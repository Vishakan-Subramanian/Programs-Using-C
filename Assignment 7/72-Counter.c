/*1.
Write a C program to read the text file input.txt  and display it on the console.
2.	
Modify Program.1 to count the number of characters, spaces, digits in that file */

#include<stdio.h>
#include<ctype.h>

int main(){
	FILE *ptr;
	char ch;
	int cc=0,cs=0,cd=0;
	printf("\nOpening File input.txt and printing its contents..."); 
	ptr=fopen("C:\\Users\\Vishakan\\Desktop\\input.txt","r"); ///opening file in R mode
	
	if(ptr==NULL){  //if file not found
		fclose(ptr);
		printf("\nSource File was not found.");
		return 0;
	}
	printf("\nContents: \n");
	ch=getc(ptr);
	while(!feof(ptr)){  //reading till end of file is reached
		
		printf("%c",ch);
		if(isalpha(ch))
			cc++;
		if(isdigit(ch))
			cd++;
		if(ch==' ')
			cs++;
		ch=getc(ptr);
	}

	printf("\n\nThe number of characters in the file are %d.\nThe number of spaces in the file are %d.\nThe number of digits in the file is %d.",cc,cs,cd);
	fclose(ptr);
	return 0;
}
/*
C:\Users\Vishakan\Desktop>type input.txt
Hey
Welcome to C programming
This is a demo of files in C
Hope you liked it
For more demos, visit lms.ssn.edu.in
Contact me at 192.168.1.1
C:\Users\Vishakan\Desktop>gcc 72-Counter.c -o h

C:\Users\Vishakan\Desktop>h

Opening File input.txt and printing its contents...
Contents:
Hey
Welcome to C programming
This is a demo of files in C
Hope you liked it
For more demos, visit lms.ssn.edu.in
Contact me at 192.168.1.1 

The number of characters in the file are 98.
The number of spaces in the file are 20.
The number of digits in the file is 8.
*/
