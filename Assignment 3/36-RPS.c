/*6. Rock Paper Scissors */
#include<stdio.h>
#include<stdlib.h>
void main(){
	printf("Rock Paper Scissors\n");
	int uo,co,k=0,n=0;
	while(n<=10){
		pos1:
		printf("Enter an option.\n1 for Paper\n2 for Scissors\n3 for Rock\n");
		scanf("%d",&uo);
		if(uo<=0||uo>3)
			goto pos1;
		co=rand()%3+1;
		switch(co){
			case 1: printf("Computer chose Paper.\n"); break;
			case 2: printf("Computer chose Scissors.\n"); break;
			case 3: printf("Computer chose Rock.\n"); break;
		}
		if(uo==co){
			printf("Draw.\n");
			}
		else if((uo==1&&co==3)||(uo==2&&co==1)||(uo==3&&co==2)){
			printf("You win.\n");
			k++;
			}
		else
			printf("You lose.\n");
		n++;
		}	
	
	if(k>5)
		printf("You win overall.");
	else if(k==5)
		printf("It's an overall draw!");
	else
		printf("You lose overall.");
		
	}
	
/*
[root@sel-25 196 CSE C]# ./rps
Rock Paper Scissors
Enter an option.
1 for Paper
2 for Scissors
3 for Rock
1
Computer chose Rock.
You win.
Enter an option.
1 for Paper
2 for Scissors
3 for Rock
2
Computer chose Rock.
You lose.
Enter an option.
1 for Paper
2 for Scissors
3 for Rock
3
Computer chose Scissors.
You win.
Enter an option.
1 for Paper
2 for Scissors
3 for Rock
1
Computer chose Scissors.
You lose.
Enter an option.
1 for Paper
2 for Scissors
3 for Rock
2
Computer chose Rock.
You lose.
Enter an option.
1 for Paper
2 for Scissors
3 for Rock
3
Computer chose Scissors.
You win.
Enter an option.
1 for Paper
2 for Scissors
3 for Rock
1
Computer chose Paper.
Draw.
Enter an option.
1 for Paper
2 for Scissors
3 for Rock
2
Computer chose Paper.
You win.
Enter an option.
1 for Paper
2 for Scissors
3 for Rock
3
Computer chose Scissors.
You win.
Enter an option.
1 for Paper
2 for Scissors
3 for Rock
1
Computer chose Rock.
You win.
Enter an option.
1 for Paper
2 for Scissors
3 for Rock
2
Computer chose Rock.
You lose.
You win overall.
*/