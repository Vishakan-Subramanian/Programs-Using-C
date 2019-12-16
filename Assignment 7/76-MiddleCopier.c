/*6. 
Search for the middle content of the file say m be the location of it. Copy (m-n) to (m+n)      
contents to another file called  copy.txt. */

#include<stdio.h>

int main(){
	FILE *src,*tgt;
	char ch;
	int len=0,m,n,i=0;
	src=fopen("input.txt","r+");
	if(src==NULL){   //if source file not found
		fclose(src);
		printf("\nSource File not found.");
		return 0;
	}
	ch=fgetc(src);
	len++;
	while(!feof(src)){  //calculating the no. of characters in source file
		len++;
		ch=fgetc(src);
	}
	m=len/2;
	printf("\nEnter the index value of n: ");  //getting n from the user
	scanf("%d",&n);
	
	fseek(src,m-n,0);  //moving the cursor to the m-n position

	tgt=fopen("copy.txt","w");

	if(tgt==NULL){  //if target file is not found
		fclose(tgt);
		printf("\nTarget File not found.");
		return 0;
	}
	ch=fgetc(src);
	while(i<(2*n)){  //pasting the selected characters onto target file
		fputc(ch,tgt);
		ch=fgetc(src);
		i++;
	
		}	
fclose(src);
fclose(tgt);
return 0;
}

/*
[root@sel-25 196 CSE C]# gcc 76-MiddleCopier.c -o mc
[root@sel-25 196 CSE C]# ./mc

Enter the index value of n: 5
[root@sel-25 196 CSE C]# cat input.txt
HZ
WZlcZmZ tZ C
ThZs Zs VZshZkZn
WhZt's Zp?
TZmZ tZ slZZp.
[root@sel-25 196 CSE C]# cat copy.txt;
ZshZkZn
Wh
*/
