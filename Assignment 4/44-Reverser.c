/* string reverser in minimum swaps */
#include<string.h>
#include<stdio.h>
void main(){
	char s[100],temp;
	printf("Reverser\n");
	printf("\nEnter text to reverse: ");
	gets(s);
	int n=strlen(s),i=0;
	while(i<n/2){
		temp=s[i];
		s[i]=s[n-i-1];
		s[n-i-1]=temp;
		i++;
	}
	printf("The reversed text is:\n%s",s);
}

/*
[root@sel-25 196 CSE C]# ./rev
Enter text to reverse: The quick brown fox jumps over the lazy dog
The reversed text is:
god yzal eht revo spmuj xof nworb kciuq ehT
*/