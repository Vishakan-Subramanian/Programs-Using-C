/*
1.
Write a C program to read the text file input.txt  and display it on the console.
2.	
Modify Program.1 to count the number of characters, spaces, digits in that file 
3.
Modify Program.2 to count the number of words, lines in the same file.
*/

#include<stdio.h>
#include<ctype.h>

int main(){
	FILE *ptr;
	char ch;
	int cc=0,cs=0,cd=0,cw=0,cl=1;
	printf("\nOpening File input.txt and printing its contents..."); 
	ptr=fopen("input.txt","r"); ///opening file in R mode
	
	if(ptr==NULL){  //if file not found
		fclose(ptr);
		printf("\nSource File was not found.");
		return 0;
	}
	printf("\nContents: \n");
	ch=getc(ptr);
	while(!feof(ptr)){  //reading till end of file is reached
		printf("%c",ch);

		cc++;
		if(isdigit(ch))
			cd++;
		if(ch==' '){
			cs++;
		}
		if(ch=='\n'){
			cl++;
		}
		if(!(isalnum(ch)))
			cw++;
		ch=getc(ptr);

	}

	printf("\n\nThe number of characters in the file are %d.\nThe number of spaces in the file are %d.\nThe number of digits in the file is %d.\nThe number of words in the file is %d.\nThe number of lines in the file is %d.",cc,cs,cd,cw,cl);
	fclose(ptr);
	return 0;
}
/*
C:\Users\Vishakan\Desktop>gcc 73-LineRead.c -o h

C:\Users\Vishakan\Desktop>h
Opening File input.txt and printing its contents...
Contents:
This is ssn college of engineering at tamilnadu. tamilnadu is otherwise called a
s singara tamilnadu

The number of characters in the file are 99.
The number of spaces in the file are 14.
The number of digits in the file is 0.
The number of words in the file is 15.
The number of lines in the file is 1.
*/
