/* 2. Given multiple lines of text, parse the text to separate the tokens. A token is a word separated
by a space. Store the multiple lines of text as individual strings whose maximum length is
unspecified. Maintain a pointer to each string within a one-dimensional array of pointers.
Identify the last line of text in some pre-determined manner. (Eg. STOP) */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void token(int n, char *str[]);
void main()
{
	char *str[30];  //1 D pointer array
	int n=0, i=0, j=0;
	
	for(i=0; i<30; i++)
		str[i] = (char *) malloc(sizeof(char)*30); //default memory allocation, i.e 30 characters for each string
	
	do 
	{	
		printf("\nEnter a line of text.Enter \"STOP\" to stop the text read.\n"); // input strings from user
		scanf(" %[^\n]", str[n]);
	}while(strcmp(str[n++], "STOP")!=0);  //to stop accepting input if "STOP" is given.
	
	n--; //to exclude the "STOP" string
	token(n,str);
}

void token(int n, char *str[]){
	int  i=0,j=0;
	printf("\nThe Tokens are: ");
	for(i=0;i<n;i++)
	{ //to traverse through all the stored strings
		printf("\n\nIn String %d:\n", i+1); 
		for(j=0;*(str[i]+j);j++)
		{ //parsing the string into tokens
			if(isalnum(*(str[i]+j)))
				printf("%c", *(str[i]+j)); //separating into tokens
			else
				printf("\n");  //breaking if the next token appears
		}
	}
}
/*
[root@sel-25 196 CSE C]# ./t
Enter a line of text.Enter "STOP" to stop the text read.
The quick brown fox jumps over the lazy dog

Enter a line of text.Enter "STOP" to stop the text read.
C programming is the best!

Enter a line of text.Enter "STOP" to stop the text read.
STOP

The Tokens are:

In String 1:
The
quick
brown
fox
jumps
over
the
lazy
dog

In String 2:
C
programming
is
the
best
*/