								/* Simpsons 1/3 rd Rule */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include<string.h>
#include<math.h>


#define f(y) 1/(1+y)		// The function defined by #define
#define a 0.0				// The  lower limit	
#define b 1.0				// The upper limit

int main(void) {
	int iter=1;
	printf("Enter the even number of iterations  : ");	// Even number of iterations 
	int iteration;
	scanf("%d",&iteration);
	double h=(b-a)/iteration;			// Width length
	double x=a;
	double result=f(a);		
	double error=0.0001;
	while(iter<iteration) {
		x=x+h;
		double temp=f(x);
		result+=(iter%2==0)?(2*temp):(4*temp);	//Computing the result over the intervals with ternary operator
		iter++;
	}
	result+=f(b);
	result=result*h/3.0;
	if((result-error)>error)
		printf("The Result After Integration is  : %0.4f",result+error);	// Integration result
}
