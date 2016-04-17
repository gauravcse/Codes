#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define e 2.7182818
int main() {
	double a,b,c;
	a=0.0;
	b=1.0;
	double fc=0.0;
	int flag=1;
	do {
		c=(a+b)/2;
		fc=(pow(e,c)-(3*c));
		printf("fc=%0.5f\n",fc);
		if(fc>0)
		  a=c;
		else if(fc<0)
		  b=c;
		printf("a=%f b=%f \n",a,b);
	} while((fc>0.0000001)||(fc<-0.0000001));
	printf("\nSOLUTION OF THE EQUATION IS %0.7f",c);
}
