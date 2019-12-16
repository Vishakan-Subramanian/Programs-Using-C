/*1. Write a C function that searches a given word in a line of text and returns the frequency count.
Make use of pointer notation */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void frequency(char *ch, char *word);
void main(){
	char *str, *word;
	str = (char *) malloc(sizeof(char)*100);
	word =  (char *) malloc(sizeof(char)*15);

	printf("\nEnter string: ");
	scanf(" %[^\n]", str);
	printf("\nEnter word to be searched: ");
	scanf(" %[^\n]", word);
	frequency(str, word);
}

void frequency(char *str, char *word)
{
	int freq=0,i,j,flag;
	char chk;
	for(i=0; *(str+i)!='\0'; i++)
	{
		if(*(str+i) == *word) //checking if str[i]==word[0]
		{
			flag = 1;
			for(j=0;j<strlen(word);j++) //checking if rest of characters are same.
				if(*(str+i+j) != *(word+j)){
					flag=0;
					break;
				}
				chk=*(str+i+j);
				if(isalpha(chk))
					flag=0;
			if(flag==1)
				freq+=1;			
		}
	} 
	printf("\nFrequency of the word \"%s\" is: %d",word,freq);	
}
/* 
[root@sel-25 196 CSE C]# ./f

Enter string: the quick brown fox jumps quickly over the quick dog

Enter word to be searched: quick

Frequency of the word "quick" is: 2

*/

