                                            /* Computing the two roots of f(x)=x^2-x-6 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
    
    // Computing the root by Substituition Method first for f(x)=(x^2-6)^(0.5) and then for g(x)=-(x^2-6)^(0.5)

    double x=1.0;    //The value to be found out
    double fx,gx;
    fx=sqrt(x+6);
    gx=-sqrt(x+6);
   
    while((fx-x)>=0.00005 || (fx-x)<=-0.00005) {
   
        printf("The value of f(x) at x=%0.5f is %0.5f\n",x,fx);
        x=fx;
        fx=sqrt(x+6);            
    
    }

    printf("The root of the equation is %0.5f\n",fx);

    while((gx-x)>0.00005 || (gx-x)<-0.00005) {
   
        printf("The value of g(x) at x=%0.5f is %0.5f\n",x,gx);
        x=gx;
        gx=-sqrt(x+6);            
    
    }

    printf("The root of the equation is %0.5f\n",gx);

}

    
    
    
