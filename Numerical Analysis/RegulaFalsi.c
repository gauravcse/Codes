#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include<string.h>
#include<math.h>


#define f(x) x*x-x-6

int main(void)
{
	float r0,r1,r2;
	int i=1;
	printf("Please input initial approximations: ");
	scanf("%f %f",&r0,&r1);
//	printf("----------------------------------------------------------------------------------------------------------\n");
    	printf("Iteration	     X0		     X1		  f(X0)	              f(X1)	   X2	         |X1-X0|\n");
    	printf("----------------------------------------------------------------------------------------------------------\n");
	
	do
	{
		r2=(r0*(f(r1))-r1*(f(r0)))/((f(r1))-(f(r0)));
		printf("  %d		  %0.5f	   %0.5f       %0.5f	     %0.5f	 %0.5f	 %0.5f\n",i,r0,r1,(f(r0)),(f(r1)),r2,fabs(r2-r1));
		r0=r1;
		r1=r2;
		i++;
	}while(fabs(r0-r1)>0.000005);
	//printf("----------------------------------------------------------------------------------------------------------\n");
	
	printf("\n\nThe actual root is: %f\n\n",r1);
	return 0;
	
}
	
	
