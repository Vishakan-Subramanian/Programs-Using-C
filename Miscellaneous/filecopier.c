/*to copy the contents of one file to another using a C program*/

#include<stdio.h>
int main(){
	FILE *src,*tgt;   //creating 2 file pointers
	char ch;
	printf("\nCopying from file \'Source.txt\'");
	src=fopen("C:\\Users\\Vishakan\\Desktop\\Source.txt","r");  //locating the source file
	if(src==NULL){  //if file not found
		fclose(src);
		printf("\nSource File was not found.");
		return 0;
	}

	tgt=fopen("C:\\Users\\Vishakan\\Desktop\\Target.txt","w");  //locating the target file
	if(tgt==NULL){  //if file not found
		fclose(tgt);
		printf("\nTarget File was not found.");
		return 0;
	}

	while(!feof(src)){  //copying char by char till EOF is reached.
		ch=fgetc(src);
		fputc(ch,tgt);
	}

	fclose(src);
	fclose(tgt);
	printf("\nCopying was successful.");

	return 0;

}


/*
OUTPUT:
C:\Users\Vishakan\Desktop>type Source.txt
Hey
Welcome to File Handling with C!

C:\Users\Vishakan\Desktop>type Target.txt

C:\Users\Vishakan\Desktop>gcc filecopier.c -o f

C:\Users\Vishakan\Desktop>f

Copying from file 'Source.txt'
Copying was successful.
C:\Users\Vishakan\Desktop>type Target.txt
Hey
Welcome to File Handling with C!

*/