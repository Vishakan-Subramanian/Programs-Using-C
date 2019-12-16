/*
10. Create a telephone directory and perform the following operations: insert, update, delete and
 append telephone details of an individual into the telephone directory using random access file.
 (Hint: Use structure to represent the telephone record and have necessary attributes such
 as name, address, phone_number) 
 */

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
 char name[50];
 char add[100];
 char no[10];

}Customer;

void AddData(int *n);
void UpdateData(int n);
void DelData(int *n);
void DisplayData(int n);

int main()
{
	int n=0,choice;
	p:
	printf("\n\t\tMENU:");
	printf("\nPress 1 to Add a Record\nPress 2 to Delete a Record\nPress 3 to Update a Record\nPress 4 to Display the Records \nPress 5 to quit");
	printf("\nENTER YOUR CHOICE :");
	scanf(" %d",&choice);
	switch(choice)
	{
		case 1 : AddData(&n);
		         goto p;
		case 2:  DelData(&n);
		         goto p;
		case 3: UpdateData(n);
		         goto p;
		case 4: DisplayData(n);
		         goto p;
		case 5: 
                goto e;
		default : 
                goto p;
	}
	e:
	 printf("\n\n     Thank you!   ");
	 return 0;
}

void AddData(int *n)			//to add a record to the file
{
    FILE *fp;
    fp=fopen("tel.dat","ab+");
	Customer c;
	printf("NAME: ");
    scanf(" %[^\n]",c.name);
        
    printf("PHONE : ");
    scanf(" %[^\n]",c.no);

    printf("ADDRESS: ");
    scanf(" %[^\n]",c.add);
	fwrite(&c,sizeof(c),1,fp);
    fclose(fp);
	(*n)++;
}

void UpdateData(int n)			//to update a record
{
	FILE *fp;
    int i,f=0,k;
    Customer p;
    char name[50];
    fp=fopen("tel.dat","rb+");
    printf("\nENTER THE NAME OF THE RECORD TO UPDATE: ");
    scanf(" %[^\n]",name);
    k=sizeof(p);
    for(i=0;i<n;i++)
    {
    	
        fread(&p,sizeof(p),1,fp);
        if(strcmp(name,p.name)==0)
        {    				
                    printf("\nENTER THE NEW NAME :");
					scanf(" %[^\n]",p.name);

                   printf("\nENTER THE NEW PHONE NUMBER : ");
                   scanf(" %[^\n]",p.no);


                    printf("\nENTER THE NEW ADDRESS: ");
                    scanf(" %[^\n]",p.add);
                    
    				fseek(fp,-1*k,1);
    				fwrite(&p,sizeof(p),1,fp);
    				f=1;
        }
    }
    if(f==1)
    printf("\nRecord updation successful.\n");
    else
    printf("\nUpdation failed.\n");
    fclose(fp);
}	

void DelData(int *n)			//to delete a record
{
	FILE *fp,*fo;
    int i=0,k=0;
    char name[20];
    Customer c;

    printf("\nENTER THE NAME OF THE PERSON WHOSE RECORD IS TO BE DELETED: ");
    scanf(" %[^\n]",name);

    fp = fopen("tel.dat","rb+");
    fo = fopen("Temp.dat","wb+");

    while(fread(&c,sizeof(c),1,fp))
    {
       if(strcmp(name,c.name)!=0)
       {
	       fwrite(&c,sizeof(c),1,fo);
	   }
	   else
	       k=1;
    }

    fclose(fp);
    fclose(fo);
    remove("tel.dat");
    rename("Temp.dat","tel.dat");
    if(k==1)
    {
	    *n--;
	    printf("\nRecord deletion successful.\n");
    }
    else
    printf("\nRecord was not found.\n");
}

void DisplayData(int n)				//to display the available records
{
	int i;
	FILE *fp;
	Customer c;
	fp=fopen("tel.dat","rb");
	while(fread(&c,sizeof(c),1,fp))
	   {
	       	

            printf("\nNAME: %s",c.name);
            printf("\nTELEPHONE NUMBER:%s ",c.no);
            printf("\nADDRESS: %s ",c.add);
     
	   }

	fclose(fp);
}

/*
[root@sel-25 196 CSE C]# gcc 711-CountryCapital.c -o cc
[root@sel-25 196 CSE C]# ./cc

                MENU:
Press 1 to Add a Record
Press 2 to Delete a Record
Press 3 to Update a Record
Press 4 to Display the Records
Press 5 to quit
ENTER YOUR CHOICE :1
NAME: Sharan
PHONE : 191
ADDRESS: abc

                MENU:
Press 1 to Add a Record
Press 2 to Delete a Record
Press 3 to Update a Record
Press 4 to Display the Records
Press 5 to quit
ENTER YOUR CHOICE :1
NAME: Vishakan
PHONE : 292
ADDRESS: bcd

                MENU:
Press 1 to Add a Record
Press 2 to Delete a Record
Press 3 to Update a Record
Press 4 to Display the Records
Press 5 to quit
ENTER YOUR CHOICE :1
NAME: Sreyas
PHONE : 494
ADDRESS: age

                MENU:
Press 1 to Add a Record
Press 2 to Delete a Record
Press 3 to Update a Record
Press 4 to Display the Records
Press 5 to quit
ENTER YOUR CHOICE :4

NAME: Sharan
TELEPHONE NUMBER:191
ADDRESS: abc
NAME: Vishakan
TELEPHONE NUMBER:292
ADDRESS: bcd
NAME: Sreyas
TELEPHONE NUMBER:494
ADDRESS: age
                MENU:
Press 1 to Add a Record
Press 2 to Delete a Record
Press 3 to Update a Record
Press 4 to Display the Records
Press 5 to quit
ENTER YOUR CHOICE :3

ENTER THE NAME OF THE RECORD TO UPDATE: Sharan

ENTER THE NEW NAME :SharanGiri

ENTER THE NEW PHONE NUMBER : 494

ENTER THE NEW ADDRESS: abc

Record updation successful.

                MENU:
Press 1 to Add a Record
Press 2 to Delete a Record
Press 3 to Update a Record
Press 4 to Display the Records
Press 5 to quit
ENTER YOUR CHOICE :4

NAME: SharanGiri
TELEPHONE NUMBER:494
ADDRESS: abc
NAME: Vishakan
TELEPHONE NUMBER:292
ADDRESS: bcd
NAME: Sreyas
TELEPHONE NUMBER:494
ADDRESS: age
                MENU:
Press 1 to Add a Record
Press 2 to Delete a Record
Press 3 to Update a Record
Press 4 to Display the Records
Press 5 to quit
ENTER YOUR CHOICE :2

ENTER THE NAME OF THE PERSON WHOSE RECORD IS TO BE DELETED: Sreyas

Record deletion successful.

                MENU:
Press 1 to Add a Record
Press 2 to Delete a Record
Press 3 to Update a Record
Press 4 to Display the Records
Press 5 to quit
ENTER YOUR CHOICE :4

NAME: SharanGiri
TELEPHONE NUMBER:494
ADDRESS: abc
NAME: Vishakan
TELEPHONE NUMBER:292
ADDRESS: bcd
                MENU:
Press 1 to Add a Record
Press 2 to Delete a Record
Press 3 to Update a Record
Press 4 to Display the Records
Press 5 to quit
ENTER YOUR CHOICE :5


     Thank you!
*/