/*1.
Write a C program to read the text file input.txt  and display it on the console. */

#include<stdio.h>

void content(FILE *fp)
{   char c;
	if (fp == NULL)                                //If file doesn't exist.
		printf("\nFile not found.");
	else
	{   
		printf("\nThe File Contents are:\n");
		do {
			fscanf(fp, "%c", &c); 
            if(!feof(fp))                            
			{
               printf("%c", c);
            }
		} while (!feof(fp));
		fclose(fp);                                                     
	}
}