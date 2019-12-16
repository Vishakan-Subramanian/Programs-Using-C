/*to find the last occurrence of a substring in a given string */
#include<stdio.h>
#include<string.h>
void main(){
	char str[100],sub[10];
	int ind=-1,val=0,i=0,j=0,n=0;
	printf("Finding the last occurrence of a substring.\n"); //getting the reqd. inputs
	printf("Enter a string: ");
	gets(str);
	printf("\nEnter a substring: ");
	scanf("%s",&sub);
	int len=strlen(sub);
	char temp[len];
	while(i<strlen(str)){   //checking the string for occurrence of the substring
		j=0;  
		n=i;
		while(j<len){   //forming a temporary string from the original string
			temp[j]=str[i+j];
			j++;
		}
		val=strcmp(temp,sub);   //comparing given substring with temp. string
		if(val!=0){
			n=-1;
		}
		else
			ind=i;
		i++;
	}
	if(ind!=-1)
		printf("\nThe last occurrence of %s in %s is at index %d.",sub,str,ind);
	else
		printf("\nThe substring %s was not found in the string %s.",sub,str);
}

/*
[root@sel-25 196 CSE C]# ./o
Finding the last occurrence of a substring.
Enter a string: Assassination

Enter a substring: ass
The last occurrence of ass in Assassination is at index 3.
*/