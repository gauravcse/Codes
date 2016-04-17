#include<stdio.h> 
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
 

#define f(x) (x*x-x-6) 
#define df(x) (2*x-1)   

int main(void){ 

	int z=1; 
	float x,x1=0.0; 
	printf("Please input The value for x: "); 
	scanf("%f",&x); 
	printf("\n\n Iteration no\t X\t\t X1\t\t f(X1)\t |X-X1| \n");
	//printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
	
	do{ 
	x1=x; 
	x=x1-(f(x1)/df(x1)); 
	printf("\t%d \t %lf \t %lf \t %lf \t %lf\n",z,x,x1,f(x1),fabs(x-x1)); 
	z++; 
	    }while(fabs(x-x1)>0.000005); 

printf("\n\t So the actual root is: %lf\n",x); 

}
