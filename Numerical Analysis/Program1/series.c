// The Sum of the series 1/(1-x)
#include<stdio.h>
#include<stdlib.h>

int series(void) {
    
    float i;
    int count=1;
    printf("--------------------------------------------\n");
    printf("Index			Degree				Value\n");
    printf("--------------------------------------------\n");
    for(i=-0.9;i<=0.9;i+=0.1) {
        float x=i;
        float sum=1;
        float term = x;
        while ( term > 0.0001 || term < -0.0001 ) {
            
            sum+=term;
            term*=x;
 
       }
       if (i < 0.0)
          printf("   %d			%d			%0.5f\n",count,i,sum);
       else
           printf("   %d			%d			%0.5f\n",count,i,sum);
        count++;
    }
    return 0;

}

