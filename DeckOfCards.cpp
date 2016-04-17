#include<stdio.h>
#include<stdlib.h>
void numberprint(int x);
int main() {
	int count=5;
	srand(9);
	while(count) {
	int random;
	random=(rand()%52+1);
	if(random<=13) 
		printf("SPADE ");
	else if((random>13)&&(random<=26))
	    printf("CLUB ");
	else if((random>26)&&(random<=39))
	    printf("DIAMOND ");
	else 
	    printf("HEART ");
	numberprint(random%13);
	count--;
	}
}
void numberprint(int x) {
	switch(x) {
		case 1: printf("A\n");
		        break;
		case 11: printf("KING\n");
		        break;
		case 12: printf("QUEEN\n");
		         break;
		case 13: printf("JACK\n");
                 break;
		default: printf("%d\n",x);
		         break;
	}
	return;
}
