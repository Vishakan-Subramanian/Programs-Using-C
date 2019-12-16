/*
8.29 The program given in Example 8.4 can easily be modified to minimize a function of x. This minimization
procedure can provide us with a highly effective technique for calculating the roots of a nonlinear algebraic 
equation. For example, suppose we want to find the particular value of x that causes some function f(x) to equal
zero. A typical function of this nature might be
f(x) = x + cos(x) - 1 -sin(x).
If we let y(x) =f(x)^2, then the function y(x) will always be positive, except for those values of x that are roots of
the given function [i.e., for which f(x), and hence y(x), will equal zero]. Therefore, any value of x that causes y(x)
to be minimized will also be a root of the equation f(x) = 0.
Modify the program shown in Example 8.4 to minimize a given function. Use the program to obtain the roots
of the following equations:
(a) x + cos(x) = 1 + sin(x), n/2 <x < n
(6) x5 + 3x2 + 10, 0 <= x <= 3 (see Example 6.21) 
*/

/* find the maximum of a function within a specified interval */

#include <stdio.h>
#include <math.h>

#define CNST 0.0001

double a, b, xl, yl, xr, yr,c,d,e,f; /* global variables */
int opt;

void maximise(); /* function prototype */
double curve(double xl); 
void minimise(); 
void zerofinder();


int main()
{
	double xmax, ymax,xmin,ymin;
	/* read input data (interval end points) */
	printf("\nSelect the curve:\n1 for xcosx\n2 for x+cosx=sinx+1\n3 for x^5+3x^2+10\n");
	scanf("%d",&opt);
	printf ("\na = ");
	scanf ("%lf",&a) ;
	printf ("b = ");
	scanf ("%lf",&b) ;
	c=a;
	d=b;
	e=a;
	f=b;
	/* interval reduction loop */
	do{
		maximise();
	}while ((yl != yr) && ((b - a) > 3 * CNST));

	/* calculate xmax and ymax, and display the results */
	xmax = 0.5 * (xl + xr);
	ymax = curve(xmax);
	printf("\nxmax = %8.6lf  ymax = %8.6lf",xmax,ymax);
	/* interval reduction routine */

	do{
		minimise();
	}while ((yl != yr) && ((d - c) > 3 * CNST));

	/* calculate xmin and ymin, and display the results */
	xmin = 0.5 * (xl + xr);
	ymin = curve(xmin);
	printf("\nxmin = %8.6lf  ymin = %8.6lf",xmin,ymin);
	printf("\n");
	zerofinder();
	return 0;
}	

void maximise()
{	
	xl = a + 0.5 * (b - a - CNST);
	xr = xl + CNST;
	yl = curve(xl);
	yr = curve (xr);
	if(yl>yr) { /* retain left interval */	
		b = xr;
		//return;
	}
	else if (yl<yr) /* retain right interval */
		a = xl;
	//return;
}
void minimise(){
	xl = c + 0.5 * (d - c - CNST);
	xr = xl + CNST;
	yl = curve(xl);
	yr = curve (xr);
	if(yl<yr) { /* retain left interval */	
		d = xr;
		//return;
	}
	else if (yl>yr) /* retain right interval */
		c = xl;
	//return;	
}

void zerofinder(){		//finding zeroes of the function 
	int count=0;
	double temp1,temp2,roots[10];
	for(e;e<f;e=e+CNST){
		temp1=pow(curve(e),2);
		temp2=pow(curve(e+CNST),2);
		if(temp1<CNST){	//comparing f(x)^2 value to 0.000000001 
			if(count==0){
				printf("\nRoot %d: x = %8.6lf",count+1,e);	//approximate checking
				roots[count]=e;
				count++;
			}
			else{
			if(abs(roots[count-1]-e)>0.1){		//to ensure roots aren't repeated
				printf("\nRoot %d: x = %8.6lf",count+1,e);	//approximate checking
				roots[count]=e;
				count++;
			}
			}
		}
	}
}

/* evaluate the function y = f(x) */
double curve(double x)
{

switch(opt){
	case 1:
			return (x * cos(x));
	case 2:
			return(x+cos(x)-1-sin(x));
	case 3:
			return(pow(x,5)+(3*pow(x,2))+10);
	default:
			printf("\nInvalid option.");
}

}


/*
C:\Users\Vishakan\Downloads>b

Select the curve:
1 for xcosx
2 for x+cosx=sinx+1
3 for x^5+3x^2+10
2

a = 0
b = 3.4

xmax = 3.399846  ymax = 1.688401
xmin = 1.570823  ymin = -0.429204

Root 1: x = 0.000000
Root 2: x = 2.402700


C:\Users\Vishakan\Downloads>b

Select the curve:
1 for xcosx
2 for x+cosx=sinx+1
3 for x^5+3x^2+10
1

a = 0
b = 6

xmax = 0.860448  ymax = 0.561096
xmin = 3.425713  ymin = -3.288371

Root 1: x = 0.000000
Root 2: x = 1.564500
Root 3: x = 4.710300


C:\Users\Vishakan\Downloads>b

Select the curve:
1 for xcosx
2 for x+cosx=sinx+1
3 for x^5+3x^2+10
3

a = -3
b = 0

xmax = -1.062576  ymax = 12.032638
xmin = -2.999767  ymin = -205.909805

Root 1: x = -1.819500

*/