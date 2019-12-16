/*8. 
Read the following contents
 “This is ssn college of engineering at chennai. Chennai is otherwise called as singara
 chennai”
 from the console and write it to a file. Whenever you encounter chennai record its position
 using fgetpos(). Then replace it with Tamilnadu using fsetpos().
 Output: Final content of the file:
 “This is ssn college of engineering at Tamilnadu. Tamilnadu is otherwise called as singara
 Tamilnadu” 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"read.h"  //creating a custom header file to display file contents

FILE *fp;

void fwriter();  //function to write to file from console

void main()
{
	
	int i=0,count=0,k=0,l1,l2,n=0;
	char s1[100],s2[100],ch;
	strcpy(s1,"chennai");                            
	strcpy(s2,"tamilnadu");                          
	l1=strlen(s1);                                  
	l2=strlen(s2);
	fwriter();
	fp=fopen("input.txt","r+");                      //Opening the file in r+ mode 
	fpos_t pi,p,pf,pii;                                //Declaring variables to save the positions 
	pii=pi;                                        //Storing the position of beginning again in another variable
        fgetpos(fp,&pi);                               //Saving the position 
	fseek(fp,0,2);                                 //Moving pointer to EOF
	fgetpos(fp,&pf);                               //saving this location 
	fseek(fp,0,0);                                 //Going back to beginning
	while(!feof(fp))
	{
        fgetpos(fp,&p);                       //Saving position 
		ch=fgetc(fp);                                               
		if(!feof(fp))
		{
			for(i=0;i<l1;i++)                 //To compare if string is same as chennai
			{
				if(s1[i]==tolower(ch))     //for caseless match
				{
					ch=fgetc(fp);
				}
				else
				{
					k=1;	           // If char is not matching
				}
			}
			if(k==0)
			{
				pi=p;                      //saving position of p at pi
				fseek(fp,-1,2);            //moving file pointer to last element before EOF
				fgetpos(fp,&p);            //to save position in variable p
				while(pi!=p)                //Loop to increase the spaces to accomodate tamilnadu (prevent overwriting).
				{
					ch=fgetc(fp);         //to save character
					fseek(fp,-1,1);       //To move pointer back to same location as getc increments the position by 1
					fputc(' ',fp);        
					fputc(' ',fp);
					fputc(ch,fp);  
					fseek(fp,-4,1);     //To move the character back to the previous element before the last character in original file
					fgetpos(fp,&p);     //Save this position
				}
				for(i=0;i<l2;i++)
				{
					fputc(s2[i],fp);             // Copy characters in s2 into the file
				}
			        fseek(fp,pii+l2,0);
                  
			}
			k=0;			
		}
	}
	fclose(fp);
        printf("\nFile was modified successfully.\n");
        content(fopen("input.txt","r"));
}

void fwriter(){
	int i=0;
	char s[400];
	fp=fopen("input.txt","w");		//opening file in w mode
	if(fp==NULL){
		printf("File does not exist");
		exit(1);
	}
	printf("\nFile opened.\nEnter text to write to file: \n");
	scanf("%[^\n]",s);
	fputs(s,fp);	//writing to file
	printf("\nContent successfully written to file.");
	fclose(fp);	
}

/*OUTPUT:
[root@sel-25 196 CSE C]# gcc 78-Replace.c -o r
[root@sel-25 196 CSE C]# ./r

File opened.
Enter text to write to file:
This is ssn college of engineering at chennai. Chennai is otherwise called as singara chennai

Content successfully written to file.
File was modified successfully.

The File Contents are:
This is ssn college of engineering at tamilnadu. tamilnadu is otherwise called as singara tamilnadu

*/