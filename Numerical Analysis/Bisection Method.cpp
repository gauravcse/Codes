#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define f(x) x*x-x-6

int main(void) {
    float a,b,mid=0;
    printf("Enter the range in which the root is to be found : ");
    scanf("%f %f",&a,&b);
    printf("%f  %f \n",f(a),f(b));
    if((f(a)*f(b))>0) {
        printf("Root is not present in the interval\n");
    }
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("Iteration	   A		  B		  MID VALUE	   F(A)		 F(B)		 F(MID) 	\n");
    int iter=1;
    while(fabs(b-a)>0.0000005) {
    	mid=(a+b)/2;
    	if(fabs(f(mid)) < 0.0000001) {
    	    break;
    	}
    	//printf("Mid value : %f ",mid);
        if(((f(mid))*(f(a)))<0) {
            b=mid;
         }
        else {
            a=mid;
        }
        printf("  %d		  %0.5f	   %0.5f       %0.5f	     %0.5f	  %0.5f	     %0.5f\n",iter++,a,b,mid,f(a),f(b),f(mid));
    }
    printf("\nThe Root is : %f",mid);
}

