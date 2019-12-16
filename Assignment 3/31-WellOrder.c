/* 1. The number 138 is called well ordered because the digits in the number (1,3,8) increase from
left to right. (1 < 3 < 8). The number 365 is not well ordered. Write a program that will find
and display all possible three digit well-ordered numbers. Also display the total number of
three digit well-ordered numbers. Make use of Arrays. */

#include<stdio.h>
void main(){
	printf("List of 3 digit well-ordered numbers \n");
	int i=100,a[3],j=0,x;
	for(i=100;i<=999;i++){ //to exhaust all 3 digit numbers
		j=0;
		x=i;
		for(x;x>0;x/=10){ //to extract each digit of a number
			a[j]=x%10;
			j++;
		}
		if((a[0]>a[1])&&(a[1]>a[2])) //check condition
			printf("%d \t",i);
	}

}

/*
[root@sel-25 196 CSE C]# ./wo
List of 3 digit well-ordered numbers 
123 	124 	125 	126 	127 	128 	129 	134 	135 	136 	137 	138 	139 	145 	146 	147 	148 	149 	156 	157 	158 	159 	167 	168 	169 	178 	179 	189 	234 	235 	236 	237 	238 	239 	245 	246 	247 	248 	249 	256 	257 	258 	259 	267 	268 	269 	278 	279 	289 	345 	346 	347 	348 	349 	356 	357 	358 	359 	367 	368 	369 	378 	379 	389 	456 	457 	458 	459 	467 	468 	469 	478 	479 	489 	567 	568 	569 	578 	579 	589 	678 	679 	689 	789
*/
