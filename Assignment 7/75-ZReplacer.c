/*5.
Search for the content for the occurrence of vowel characters and replace it with ‘z’. And      
display the content of the monitor. */

#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	FILE *src,*tgt;
	char ch,temp;
	printf("\nOpening file: \'Input.txt\'\n");
	src=fopen("input.txt","r+");  			//locating the source file
	if(src==NULL){  				//if file not found
		fclose(src);
		printf("\nSource File was not found.");
		return 0;

	}
	
	tgt=fopen("sample.txt","w");
	if(tgt==NULL){
		fclose(tgt);
		printf("\nTarget File was not found.");
		return 0;
	}
	
	ch=fgetc(src);
	while(!feof(src)){
		printf("%c",ch);
		temp=toupper(ch);
		switch(temp){
			case 'A':case 'E':case'I':case'O':case'U':
				ch='Z';
				break;

		}
		fseek(src,-1,1);
		fputc(ch,src);
		ch=getc(src);

	}
	fclose(tgt);
	printf("\nContents of Input File,after rewriting: \n");
	tgt=fopen("input.txt","r");
	ch=fgetc(tgt);
	while(!feof(tgt)){
		printf("%c",ch);
		ch=getc(tgt);
	}
	fclose(tgt);
	fclose(src);
	return 0;
}

/*
[root@sel-25 196 CSE C]# gcc 75-ZReplacer.c -o z
[root@sel-25 196 CSE C]# ./z

Contents of Source File: 
Hi
Welcome to C
This is Vishakan
What's up?
Time to sleep.

Contents of Target File,after rewriting: 
HZ
WZlcZmZ tZ C
ThZs Zs VZshZkZn
WhZt's Zp?
TZmZ tZ slZZp.
*/
