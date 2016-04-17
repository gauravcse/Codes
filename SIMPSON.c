				/* Program of integration by Simpson's 1/3rd rule*/
#include<stdio.h>
#include<math.h>
#define a 0.0
#define b 1.0
#define f(x) 1/(1+x)
#define E 0.00001

int main()	{
	double h=0.0,i_1=0.0,i_2=0.0,s_1=0.0,s_2=0.0;
	int i,c=0,d=0,count=2;
	h=(b-a)/2;                                             //Interval size
	do{
		i_2=i_1;s_1=0.0,s_2=0.0;i=1;		//Iterating 5 times
		while((a+i*h)<b) {
			if(i%2==0)
            	s_1=s_1+f(a+i*h); 
       		else
         		s_2=s_2+f(a+i*h);	 
			i++;
		}
		i_1=h/3*(f(a)+f(b)+2*s_1+4*s_2);
		printf("The value of the integral after %d iteration is %0.8lf \n",count-1,i_1);	// Printing values of iterations
		h=h/2;
		count++;
	}while(count<=6);
	
	printf("FINAL VALUE OF THE INTEGRATION 1/(1+X)  : %0.4f",i_1) ;       
}

