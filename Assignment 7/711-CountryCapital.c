/*11.
Programming Problem 13.18 of textbook Byron page no. 13.40. 
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

typedef struct 	
{								 //Declaring Structure
	char country[50];
	char capital[50];
}C;                                                     
void Input();                                          
void Delete();
void CountrytoCap();
void CaptoCountry();
void List();

int main()
{
	int choice;
	p:      
	printf("\n\t\tMENU \n\tPress 1 to add a record\n\tPress 2 to delete a record\n\tPress 3 to list available data\n\tPress 4 to find capital\n\tPress 5 to find country\n\tPress 6 to quit\n\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);                                      //User Input

	switch(choice)
	{
		case 1: {
					Input();
					goto p;  
				}
		
		case 2: {
					Delete();
					goto p;
				}
		
		case 3: {
					List();
					goto p;
				}

		case 4: {
					CountrytoCap();
					goto p;
				}

		case 5: {
					CaptoCountry();
					goto p;
				}

		case 6: 
				goto e;
		default : 
				goto p;	
	}
	
	e:
	printf("\n    Thank you!   \n");
	return 0;
}

void Input()                                                               //Function Definition for input
{
	C a;
	FILE *fp=fopen("COUNTRY.dat","ab+");
	printf("Enter Country Name : ");
	scanf(" %[^\n]",a.country);
	printf("Enter Capital Name: ");
	scanf(" %[^\n]",a.capital);
	fwrite(&a,sizeof(a),1,fp);                                              //Transfer content to file
	fclose(fp);
}

void Delete()                                                               //Function Definition for deleting records
{
	FILE *fp,*fo;
	C c;
	char coun[50];
	fp=fopen("COUNTRY.dat","rb+");
	fo=fopen("temp.dat","wb+");                                               //Binary file
	printf("\nEnter Country Name to delete: ");
	scanf(" %[^\n]",coun);
	while(fread(&c,sizeof(c),1,fp))
	{
		if(strcmp(coun,c.country)!=0)
			fwrite(&c,sizeof(c),1,fo);
	}
	fclose(fp);
	fclose(fo);
	remove("COUNTRY.dat");
	rename("temp.dat","COUNTRY.dat");                                       //Renaming File
}

void CountrytoCap()                                                       //Function to display corresponding capital
{
	C c;
	char co[50];
	int flag=1;
	FILE *fp=fopen("COUNTRY.dat","rb+");
	printf("Enter Country Name: ");
	scanf(" %[^\n]",co);
	while(fread(&c,sizeof(c),1,fp))
	{
		if(strcmp(c.country,co)==0)
		{
			printf("\nThe Capital is: %s",c.capital);
			flag=0;
			break;
		}
	}
	if(flag)                                                        //If capital is not found
	{
		printf("Sorry, the specified country is not in the database.\n");
	}
	fclose(fp);
}
 
void List()
{
	C c;
	FILE *fp=fopen("COUNTRY.dat","rb+");
	printf("\nLIST OF RECORDS:\n");
	printf("\n%20s %20s %10s\n","COUNTRY   ","","  CAPITAL ");
	while(fread(&c,sizeof(c),1,fp))                                          // Reading from file
	{
		printf("%7s %-30s %-30s\n"," ",c.country,c.capital);
	}
	fclose(fp);
}

void CaptoCountry()                                                          //Function to display corresponding capital
{
	C c;
	char cap[50];
	int flag=1;
	FILE *fp=fopen("COUNTRY.dat","rb+");
	printf("Enter Capital Name : ");
	scanf(" %[^\n]",cap);
	while(fread(&c,sizeof(c),1,fp))
	{
		if(strcmp(c.capital,cap)==0)
		{
			printf("The Country is : %s",c.country);
			flag=0;
			break;
		}
	}
	if(flag)                                                //If country is not found
	{
		printf("Sorry, the capital was not found. \n");
	}
	fclose(fp);
}

/*OUTPUT:
[root@sel-25 196 CSE C]# gcc 711-CountryCapital.c -o cc
[root@sel-25 196 CSE C]# ./cc

                MENU
        Press 1 to add a record
        Press 2 to delete a record
        Press 3 to list available data
        Press 4 to find capital
        Press 5 to find country
        Press 6 to quit

Enter your choice : 1
Enter Country Name : India
Enter Capital Name: Delhi

                MENU
        Press 1 to add a record
        Press 2 to delete a record
        Press 3 to list available data
        Press 4 to find capital
        Press 5 to find country
        Press 6 to quit

Enter your choice : 2

Enter Country Name to delete: India

                MENU
        Press 1 to add a record
        Press 2 to delete a record
        Press 3 to list available data
        Press 4 to find capital
        Press 5 to find country
        Press 6 to quit

Enter your choice : 1
Enter Country Name : New Zealand
Enter Capital Name: Wellington

                MENU
        Press 1 to add a record
        Press 2 to delete a record
        Press 3 to list available data
        Press 4 to find capital
        Press 5 to find country
        Press 6 to quit

Enter your choice : 1
Enter Country Name : Australia
Enter Capital Name: Canberra

                MENU
        Press 1 to add a record
        Press 2 to delete a record
        Press 3 to list available data
        Press 4 to find capital
        Press 5 to find country
        Press 6 to quit

Enter your choice : 1
Enter Country Name : Pakistan
Enter Capital Name: Islamabad

                MENU
        Press 1 to add a record
        Press 2 to delete a record
        Press 3 to list available data
        Press 4 to find capital
        Press 5 to find country
        Press 6 to quit

Enter your choice : 3

LIST OF RECORDS:

          COUNTRY                           CAPITAL
        France                         Paris
        New Zealand                    Wellington
        Australia                      Canberra
        Pakistan                       Islamabad

                MENU
        Press 1 to add a record
        Press 2 to delete a record
        Press 3 to list available data
        Press 4 to find capital
        Press 5 to find country
        Press 6 to quit

Enter your choice : 4
Enter Country Name: New Zealand

The Capital is: Wellington
                MENU
        Press 1 to add a record
        Press 2 to delete a record
        Press 3 to list available data
        Press 4 to find capital
        Press 5 to find country
        Press 6 to quit

Enter your choice : 5
Enter Capital Name : Canberra
The Country is : Australia
                MENU
        Press 1 to add a record
        Press 2 to delete a record
        Press 3 to list available data
        Press 4 to find capital
        Press 5 to find country
        Press 6 to quit

Enter your choice : 6

    Thank you!

*/
