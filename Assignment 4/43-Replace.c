/* to replace a substring in a given string with another substring */
#include<stdio.h>
#include<string.h>
void main(){
	char s[150],sub[10],rep[10];
	int i=0,j=0,val=0,n=0,rem=0;
	printf("Enter a string: ");
	scanf("%[^\n]",s);  //Accepting a line of text, till Enter key is pressed. **IMPORTANT**
	printf("\nEnter a substring to be replaced: ");
	scanf("%s",sub);
	printf("\nEnter the replacing substring: ");
	scanf("%s",rep);
	int len=strlen(sub);
	char temp[len];
	char temps[150];
	while(i<strlen(s)){   //checking the string for occurrence of the substring
		j=0;
		while(j<len){   //forming a temporary string from the original string
			temp[j]=s[i+j];
			j++;
		}
		val=strcmp(temp,sub);   //comparing given substring with temp. string
		if(val==0){             //if match is found
			n=0;
			rem=strlen(s)-i;
			while(n<i){
				temps[n]=s[n];  //storing the characters before the to-be-modified part
				n++;
			}
			n=0;
			while(n<strlen(rep)){
				temps[i+n]=rep[n];  //replacing with new substring
				n++;
				}
			n=0;
			while(n<rem){   //putting the remaining words of the original string
				temps[i+n+strlen(rep)]=s[i+n+len];
				n++;
			}
			temps[strlen(temps)+1]='\0';  //indicating end of string
			strcpy(s,temps); //copying temporary string to original string
		}
		i++;
	}
	printf("\nThe new string is: %s.",temps);
}

/*
[root@sel-25 196 CSE C]# ./r
Enter a string: the poet wrote the book for the people

Enter a substring to be replaced: the

Enter the replacing substring: a

The new string is: a poet wrote a book for a people.
*/