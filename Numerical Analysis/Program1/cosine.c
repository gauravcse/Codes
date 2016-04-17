// The values of cosine series
#include<stdio.h>
#include<stdlib.h>
#define PI 3.1416

int cosine(void) {
    float sum,term,x,count=1;
    int n;
    int i;
    x=0.0;
    sum=0.0,term=0.0;
    printf("--------------------------------------------\n");
    printf("Index			Degree				Value\n");
    printf("--------------------------------------------\n");
    for (i=0;i<=180;i+=10) {
         
         x= (PI*i)/180.0;
         term = 1;
         sum = 1;
         n=1;
         while ((term > 0.000001) || (term < -0.000001 )) {
             
            term = (-1*x*x*term)/((2*n)*(2*n-1));
            sum+= term;
            n++;

         }
        
         printf("  %d			%d			  %0.5f\n",count++,i,sum);
     }
     return 0;
}
