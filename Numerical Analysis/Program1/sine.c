// The value of sine series
#include<stdio.h>
#include<stdlib.h>
#define PI 3.1416
#define RANGE 360

int sine(void) {
    float sum,term,x;
    int n;
    int i;
    x=0.0;
    sum=0.0,term=0.0;
    for (i=0;i<=180;i+=10) {
         
         x= (PI*i)/180.0;
         term = x;
         sum = term;
         n=1;
         while ((term > 0.000001) || (term < -0.000001 )) {
             
            term = (-1*x*x*term)/((2*n)*(2*n+1));
            sum+= term;
            n++;

         }
        
         printf("The value of sine at %d degree is %f\n",i,sum);
     }
     return 0;
}
