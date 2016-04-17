#include<stdio.h>
#include<math.h>
int  main() {
	printf("ENTER THE NUMBER WHOSE TRAILING ZEROES ARE TO FOUND OUT ");
	int number;
	scanf("%d",&number);
	int zeroes=0;
	int count=1;
	int temp=0;
	do {
		temp=(int)(number/pow(5,count));
		zeroes+=temp;
		count++;
	} while(temp!=0);
	printf("THE NUMBER OF TRAILING ZEROES ARE %d",zeroes);
}
