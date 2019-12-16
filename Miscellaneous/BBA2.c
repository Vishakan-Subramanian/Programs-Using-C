/*/*
8.4 Write a complete C program to solve each of the problems described below. Utilize programmer-defined
functions wherever appropriate. Compile and execute each program using the data given in the problem
description.
(a) Suppose you place a given sum of money, A, into a savings account at the beginning of each year for n
years. If the account earns interest at the rate of i percent annually, then the amount of money that will
have accumulated after n years, F, is given by
F=A [(I + i/100) + (1 + i/100)^2 + (1 + i/100)^3 + * - + (1 + i/100)^n]
Write a conversational-style C program to determine the following.
(i) How much money will accumulate after 30 years if $1000 is deposited at the beginning of each year
and the interest rate is 6 percent per year, compounded annually?
(ii) How much money must be deposited at the beginning of each year in order to accumulate $100,000
after 30 years, again assuming that the interest rate is 6 percent per year, with annual compounding?
In each case, first determine the unknown amount of money. Then create a table showing the total amount
of money that will have accumulated at the end of each year. Use the function written for Prob. 7.5 to
carry out the exponentiation.
(b) Modify the above program to accommodate quarterly rather than annual compounding of interest. Compare
the calculated results obtained for both problems. Hint:The proper formula is
F=A [(I + i/100rn)^m + (1 + i/100rn)^2m + (1 + i/100rn)^3m + - * + (1 + i/100rn)^nm]
where m represents the number of interest periods per year. 
*/

#include<stdio.h>
#include <math.h>
void main()
{

	int nyears,i;		//no. of years 
	float inst;		//rate of interest
	double inamt,flnamt=0;		//deposited amount , accumulated amount
	
	printf("\n\t\t\t\tSavings Account\n\n");
	
	printf("\nEnter the principal amount : ");
	scanf("%lf",&inamt);
	printf("\nEnter the rate of interest : ");
	scanf("%f",&inst);
	printf("\nNo. of years : ");
	scanf("%d",&nyears);
	for(i=1;i<=nyears;i++){
		flnamt+= pow((1 + inst/100),i);
	}
	flnamt*=inamt;

	printf("\nAcumulated amount after %d years : %lf\n",nyears,flnamt);
	
	//------------------------------------------------------------------------------
	nyears=30;
	inamt=1000;
	inst=6;
	flnamt=1;
	flnamt*=inamt;
	for(i=1;i<=nyears;i++){
		flnamt+= pow((1 + inst/100),i);
	}
	printf("\n----------------------------------------------------------------\n");
	printf("\n\nAmount deposited : %lf",inamt);
	printf("\n\nRate of interest : %f",inst);
	printf("\n\nNo. of years : %d",nyears);
	printf("\n\nAcumulated amount after %d years : %lf\n",nyears,flnamt);
	
	//------------------------------------------------------------------------------
	
	printf("\n----------------------------------------------------------------\n");
	flnamt=100000;
	nyears=30;
	inst=6;
	printf("\n\t\tAnnual Compounding\n\n");
	printf("\n\tYear\t|\tAccumulated amount\n");
	for(i=1;i<=nyears;i++){
		flnamt+= pow((1 + inst/100),i);
		printf("\n\t%d\t|\t%lf",i,flnamt);
	}

	printf("\n\n--------------------------------------------------------------\n\n");
	
	printf("\n\tYear\t|\tInitial amount\n");
	flnamt=100000;
	for(i=nyears;i>=1;i--){
		//inamt = flnamt/( pow((1 + inst/100),i)) ;
		printf("\n\t%d\t|\t%lf",i,flnamt);
		flnamt-= pow((1 + inst/100),i);
	}
	printf("\n\n--------------------------------------------------------------\n");

	flnamt=100000;
	nyears=30;
	inst=6;
	int m=4;	// m represents the number of interest periods per year
	printf("\n\t\tQuarterly Compounding\n\n");
	printf("\n\tYear\t|\tAccumulated amount\n");

	for(i=nyears;i>=1;i--){
		printf("\n\t%d\t|\t%lf",i,flnamt);
		flnamt-= pow( 1 + inst/(100*m),(i*m) );
	}
}


/*
OUTPUT : 


                                Savings Account


Enter the principal amount : 5000

Enter the rate of interest : 10

No. of years : 2

Acumulated amount after 2 years : 11550.000381

----------------------------------------------------------------


Amount deposited : 1000.000000

Rate of interest : 6.000000

No. of years : 30

Acumulated amount after 30 years : 1083.801588

----------------------------------------------------------------

                Annual Compounding


        Year    |       Accumulated amount

        1       |       100001.060000
        2       |       100002.183600
        3       |       100003.374616
        4       |       100004.637092
        5       |       100005.975318
        6       |       100007.393836
        7       |       100008.897466
        8       |       100010.491313
        9       |       100012.180791
        10      |       100013.971638
        11      |       100015.869936
        12      |       100017.882131
        13      |       100020.015057
        14      |       100022.275960
        15      |       100024.672516
        16      |       100027.212865
        17      |       100029.905636
        18      |       100032.759972
        19      |       100035.785569
        20      |       100038.992701
        21      |       100042.392260
        22      |       100045.995793
        23      |       100049.815538
        24      |       100053.864468
        25      |       100058.156333
        26      |       100062.705709
        27      |       100067.528048
        28      |       100072.639727
        29      |       100078.058107
        30      |       100083.801588

--------------------------------------------------------------


        Year    |       Initial amount

        30      |       100000.000000
        29      |       99994.256518
        28      |       99988.838139
        27      |       99983.726460
        26      |       99978.904121
        25      |       99974.354744
        24      |       99970.062879
        23      |       99966.013950
        22      |       99962.194205
        21      |       99958.590672
        20      |       99955.191112
        19      |       99951.983980
        18      |       99948.958384
        17      |       99946.104047
        16      |       99943.411277
        15      |       99940.870928
        14      |       99938.474371
        13      |       99936.213469
        12      |       99934.080542
        11      |       99932.068347
        10      |       99930.170050
        9       |       99928.379203
        8       |       99926.689725
        7       |       99925.095877
        6       |       99923.592248
        5       |       99922.173729
        4       |       99920.835504
        3       |       99919.573027
        2       |       99918.382011
        1       |       99917.258411

--------------------------------------------------------------

                Quarterly Compounding


        Year    |       Accumulated amount

        30      |       100000.000000
        29      |       99994.030687
        28      |       99988.406495
        27      |       99983.107469
        26      |       99978.114810
        25      |       99973.410805
        24      |       99968.978765
        23      |       99964.802968
        22      |       99960.868596
        21      |       99957.161694
        20      |       99953.669108
        19      |       99950.378449
        18      |       99947.278042
        17      |       99944.356887
        16      |       99941.604621
        15      |       99939.011479
        14      |       99936.568261
        13      |       99934.266300
        12      |       99932.097428
        11      |       99930.053951
        10      |       99928.128619
        9       |       99926.314602
        8       |       99924.605463
        7       |       99922.995139
        6       |       99921.477918
        5       |       99920.048416
        4       |       99918.701561
        3       |       99917.432576
        2       |       99916.236958
        1       |       99915.110465

*/