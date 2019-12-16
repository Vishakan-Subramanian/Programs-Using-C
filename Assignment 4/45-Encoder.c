/* to encode and decode a line of text */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
	char s[300];
	int j=0,min,max,c;
	printf("\nEncoding and decoding text.");
	printf("\nEnter a line of text within 300 characters.\n");
	scanf("%[^\n]",s);
	int code=rand()%127;  //generating a random number between max and min
	for(j=0;j<strlen(s);j++){  //encoding
		c=s[j];
		s[j]=c+code;	
	}
	printf("\nThe encoded line of text is:\n%s",s);
	
	for(j=0;j<strlen(s);j++){ //decoding
		c=s[j];
		s[j]=c-code;
		}
	printf("\nThe decoded line of text is:\n%s",s);	
}

/*
[root@sel-25 196 CSE C]# ./e
Encoding and decoding text.
Enter a line of text within 300 characters.
hello

The encoded line of text is:
æÄòòÿ
The decoded line of text is:
hello
*/