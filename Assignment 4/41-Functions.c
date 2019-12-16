/* implementing string functions */
#include<stdio.h>
void Catenate();
void Copy();
void Modify();
void Finder();
void Comparer();
void EndCopy();
int Length(char s[]);
void Copier(char dest[],char src[],int m);
void StringPlus(char s1[],char s2[]);
void Lowercase(char s[]);
void main(){
	int opt=0;
	char ch;
	printf("String Function Implementation");
	pos1:
	printf("\nChoose an option.\n1.Concatenation\n2.Copying\n3.Modifying characters of a string\n4.Finding occurrence\n5.Comparing two strings\n6.Copying to end of a string\n");
	scanf("%d",&opt);  //getting the menu option from the user
	if(opt<1||opt>6){
		printf("\nInvalid option.");
		goto pos1;
		}
	else{
		switch(opt){   //calling appropriate function
				case 1:
					Catenate();
					break;
				case 2:
					Copy();
					break;
				case 3:
					Modify();
					break;
				case 4:
					Finder();
					break;
				case 5:
					Comparer();
					break;
				case 6:
					EndCopy();
					break;
		}
		
	}
	pos2:
	printf("\nDo you wish to continue?\nEnter Y/N\n");
	scanf("%s",&ch);
	if(ch=='Y'||ch=='y')
		goto pos1;
	else if(ch=='N'||ch=='n')
		printf("\nGoodbye");
	else{
		printf("\nInvalid option.");
		goto pos2;
	}
}
int Length(char s[]){  //finding length of a string
	int i=0;
	while(s[i]!='\0')
		i++;
	return i+1;
	
}

void Copier(char dest[],char src[],int m){ //to copy a string to another
	int i=0;
	for(i=0;i<m;i++){
		dest[i]=src[i];
	}
	dest[m]='\0';
}

void StringPlus(char s1[],char s2[]){  //to concatenate a string to another
	int m=Length(s1);
	int n=Length(s2);
	int i=0,j=0;
	for(i=m-1;i<m+n;i++){
		s1[i]=s2[j];
		j++;	
	}
}

void Lowercase(char s[]){  //to convert a string to lowercase
	int l=Length(s); 
	int i=0;
	int c=0;
	for(i=0;i<l;i++){
		c=s[i];
		if(c>54&&c<90)
			s[i]=c+32;
	}
}

void Catenate(){  //concatenating two strings
	int n,m;
	printf("Enter the number of characters in the first string:\n");
	scanf("%d",&m);
	printf("Enter the number of characters in the second string:\n");
	scanf("%d",&n);

	char s1[m],s2[n];
	printf("\nEnter the first string: ");
	scanf("%s",s1);
	printf("\nEnter the second string: ");
	scanf("%s",s2);
	StringPlus(s1,s2);
	printf("\nAppended String: %s",s1);

}

void Copy(){  //to copy a string to another
	int n;
	printf("\nEnter the length of the string: ");
	scanf("%d",&n);
	char src[n];
	printf("\nEnter the source string: ");
	scanf("%s",&src);
	
	int m;
	printf("\nEnter the no. of characters to be copied to destination string: ");
	scanf("%d",&m);
	char dest[m];
	
	Copier(dest,src,m);
	printf("The destination string is: %s",dest);
	
}

void Modify(){  //to modify all characters to user desired character
	int m,i=0;
	printf("\nEnter the length of the string: ");
	scanf("%d",&m);
	char s[m];
	printf("\nEnter the string: ");
	scanf("%s",&s);

	char new;
	printf("\nEnter the replacing character: ");
	scanf(" %c",&new);
	
	for(i=0;i<m;i++){
		s[i]=new;	
	}
	printf("The modified string is: %s",s);
}	

void Finder(){  //finding the first occurrence of a character in a string
	int n,i=0;
	printf("\nEnter the length of the string: ");
	scanf("%d",&n);
	char s[n];
	printf("\nEnter the string: ");
	scanf("%s",&s);
	char ch;
	printf("\nEnter the character to be found: ");
	scanf(" %c",&ch);
	
	for(i=0;i<n;i++){
		if(ch==s[i]){
			n=i+1;
			printf("\nThe character was found at position %d",n);
			break;
		}
	}
	if(i==n)
		printf("\nThe character was not found.");
}

void Comparer(){ //to compare two strings
	int m,n;
	printf("\nEnter the length of string 1: ");
	scanf("%d",&m);
	char s1[m];
	printf("\nEnter string 1: ");
	scanf("%s",&s1);
	printf("\nEnter the length of string 2: ");
	scanf("%d",&n);
	char s2[n];
	printf("\nEnter string 2: ");
	scanf("%s",&s2);

	Lowercase(s1);
	Lowercase(s2);
	int val=0;
	n=(m<n)?m:n;
	for(m=0;m<n;m++){
		if(s1[m]<s2[m])
			val=-1;
		else
			val=1;
	}
	if(val==0){
		printf("\n0");
		printf("Both are same.");
	}
	else if(val==-1){
		printf("\n-1");
		printf("\n%s is lesser than %s",s1,s2);
	}
	else{
		printf("\n1");
		printf("\n%s is greater than %s",s1,s2);
	}
		
		
}

void EndCopy(){  //copying atmost n characters from s1 to s2
	int m=0,n=0,no,i=0;
	printf("\nEnter the length of source string:");
	scanf("%d",&m);
	char s1[m];
	printf("\nEnter the source string: ");
	scanf("%s",&s1);
	printf("\nEnter the length of destination:");
	scanf("%d",&n);
	char s2[n+m];
	printf("\nEnter the destination string: ");
	scanf("%s",&s2);
	
	printf("\nEnter the no. of characters to be copied from source to destination: ");
	scanf("%d",&no);
	
	for(i=0;i<no;i++)
		{
		s2[n]=s1[i];
		n++;
		}
	s2[n]='\0';
	printf("\nThe destination string is %s",s2);
	
}

/*
[root@sel-25 196 CSE C]# ./f
String Function Implementation
Choose an option.
1.Concatenation
2.Copying
3.Modifying characters of a string
4.Finding occurrence
5.Comparing two strings
6.Copying to end of a string
3

Enter the length of the string: 4

Enter the string: Aero

Enter the replacing character: a
The modified string is: aaaa
Do you wish to continue?
Enter Y/N
y

Choose an option.
1.Concatenation
2.Copying
3.Modifying characters of a string
4.Finding occurrence
5.Comparing two strings
6.Copying to end of a string
1
Enter the number of characters in the first string:
5
Enter the number of characters in the second string:
5

Enter the first string: Rolls

Enter the second string: Royce

Appended String: RollsRoyce
Do you wish to continue?
Enter Y/N
y

Choose an option.
1.Concatenation
2.Copying
3.Modifying characters of a string
4.Finding occurrence
5.Comparing two strings
6.Copying to end of a string
4

Enter the length of the string: 13

Enter the string: Assassination

Enter the character to be found: s

The character was found at position 2
Do you wish to continue?
Enter Y/N
y

String Function Implementation
Choose an option.
1.Concatenation
2.Copying
3.Modifying characters of a string
4.Finding occurrence
5.Comparing two strings
6.Copying to end of a string
6

Enter the length of source string:7

Enter the source string: Trumper

Enter the length of destination:6

Enter the destination string: Donald

Enter the no. of characters to be copied from source to destination: 5

The destination string is DonaldTrump
Do you wish to continue?
Enter Y/N
y

Choose an option.
1.Concatenation
2.Copying
3.Modifying characters of a string
4.Finding occurrence
5.Comparing two strings
6.Copying to end of a string
5

Enter the length of string 1: 6

Enter string 1: Chrome

Enter the length of string 2: 7

Enter string 2: Firefox

-1
chrome is lesser than firefox
Do you wish to continue?
Enter Y/N
y

Choose an option.
1.Concatenation
2.Copying
3.Modifying characters of a string
4.Finding occurrence
5.Comparing two strings
6.Copying to end of a string
2

Enter the length of the string: 7 

Enter the source string: Desktop

Enter the no. of characters to be copied to destination string: 4
The destination string is: Desk
Do you wish to continue?
Enter Y/N
n
Goodbye
*/

