/*4.Modify the program shown in Example 10.28 (displaying the day of the year) (Page 11.37) of
text book (Byron Gottfried)so that it can determine the number of days between two dates,
assuming both dates are beyond the base date of January 1, 1900. (Hint: Determine the number
of days between the first specified date and the base date; then determine the number of days
between the second specified date and the base date. Finally, determine the difference between
these two calculated values.)*/

#include<stdio.h>
#include<stdlib.h>
void calendar(int *pm, int *pd, int *py); 
int dayscalc(int *d, int *m, int *y);

void main(){
	int m1,d1,y1,m2,d2,y2,days;
	
	printf("\nNo.of days between 2 dates.");
	printf("\nEnter any date after January 01 1900.");
	printf("\nEnter from date.(DD MM YYYY)\n");
	calendar(&d1, &m1, &y1);
	
	printf("\nEnter to date.(DD MM YYYY)\n");
	calendar(&d2, &m2, &y2);
	
	days=dayscalc(&d1,&m1,&y1)-dayscalc(&d2,&m2,&y2);
	printf("The no. of days between the two given dates is: %d", (-days));	
}

void calendar(int *d, int *m, int *y)
{
	//to get input in the form of DD MM YYYY
	scanf(" %d %d %d", d,m,y);
}

int dayscalc(int *d, int *m, int *y)
{
	// to calculate the no of days between Jan 01 1900 and the given date
	int bd=1, bm=1, base=1900, ndays, nleft, nfour;
	
	//Number of 4 year cycles
	nfour=(*y-base)/4;
	
	//Remaining years
	nleft=(*y-base)%4;

	//no of days included in from 1900 till the last 4th year cycle
	ndays = nfour * 1461;
	
	//calculating remaining number of days in the leftover years
	if(nleft>0)
		ndays += 365 * nleft + 1;
	
	//no of days in the current year
	ndays += (long)(30.42 * (*m-1)) + *d; //approximate formula
	
	if(*m==2) //february adjustment
		ndays+=1;
	if(*m>2&&*m<8) //march to july adjustment
		ndays-=1; 
	if(*m>2&&((*y-base)%4==0)) 
		ndays+=1;  //leap year, february has passed
	
	if(ndays>59) //in case given date is lesser than Feb 28 1900 as 1900 wasn't leap.
		ndays-=1;
	
	return ndays;
}

/*
[root@sel-25 196 CSE C]# ./d

No.of days between 2 dates.
Enter any date after January 01 1900.
Enter from date.(DD MM YYYY)
27 07 2000

Enter to date.(DD MM YYYY)
27 07 2001
The no. of days between the two given dates is: 365
*/