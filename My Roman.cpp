#include<stdio.h>
int main() {
	int number;
	scanf("%d",&number);
	printf("\n");
	if(number>9999) printf("Error");
    else {
    	if(number==9000) { printf("MP"); return 0;}
    	if(number>=5000) { printf("N"); number=number-5000; }
    	if(number>=4000) { printf("MN"); number=number-4000;}
    	while(number>1000) { printf("M"); number=number-1000; }
    	if(number==900) { printf("CM"); return 0; }
    	if(number>=500) { printf("D"); number=number-500 ;}
    	if(number>=400) { printf("CD"); number=number-400; }
    	while(number>=100) { printf("C"); number = number-100; }
    	if(number==90){ printf("XC"); return 0; }
    	if(number>=50) { printf("L"); number=number-50; }
    	if(number>=40) { printf("XL"); number=number-40; }
    	while(number>=10) { printf("X"); number=number -10; }
    	if(number==9) { printf("IX");return 0; }
    	if(number>=5) { printf("V"); number=number-5; }
    	if(number==4) { printf("IV"); return 0 ;}
    	while(number>=1) { printf("I"); number=number-1 ;}
    }
}
    	
		
