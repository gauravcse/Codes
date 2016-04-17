                                            /* Computing the two roots of f(x)=e^x-4x^2 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define e 2.718

int main(void) {
    
    // Computing the root by Substituition Method first for f(x)=(x^2-6)^(0.5) and then for g(x)=-(x^2-6)^(0.5)

    double x=5.0;    //The value to be found out
    double fx,gx,hx;
    fx=log(4*x*x);
    gx=-sqrt(pow(e,x)/4);
    hx=pow(e,x)-4*x*x;
     
    /*
     * We will find out the values only if it is non-diverging
     * Firstly we will show that h(x) is diverging
     * Then we will show that f(x) and g(x) are converging and find out the roots
    */
    int iteration=1;
    double previous=0.0;
    printf("--------------------------------------------------------------------------------\n");
    printf("|  Iteration  |         |   Xi-1   |         |   X   |        |Absolute Error| \n");         

    while((hx-x)>=0.000005 || (hx-x)<=-0.000005) {

     //   printf("The value of h(x) at x=%0.6f is %0.6f\n",x,hx);
        printf("|   %d                 %0.6f                  %0.6f                 %0.6f\n",iteration++,x,hx,(x-hx));
        previous=x;
        x=hx;
        hx=pow(e,x)-4*x*x;
        if(x-previous>0) {
            
            printf("The series is diverging and hence we cannot find the root\n");
            break;
        }
    }
  
    x=5.0;
    iteration=1;
    printf("--------------------------------------------------------------------------------\n");
    printf("|  Iteration  |         |   Xi-1   |         |   X   |           |Absolute Error| \n");         

    while((fx-x)>=0.000005 || (fx-x)<=-0.000005) {

        printf("|   %d                 %0.6f                  %0.6f             %0.6f\n",iteration++,x,fx,(x-fx));
    //    printf("The value of f(x) at x=%0.6f is %0.6f\n",x,fx);
        x=fx;
        fx=fx=log(4*x*x);
    }

    printf("The root of the equation is %0.6f\n",fx);
    x=5.0;
    iteration=1;
    printf("--------------------------------------------------------------------------------\n");
    printf("|  Iteration  |         |   Xi-1   |         |   X   |        |Absolute Error| \n");         
    while((gx-x)>0.000005 || (gx-x)<-0.000005) {

        printf("|      %d               %0.6f             %0.6f            %0.6f\n",iteration,x,gx,(x-gx));   
      //  printf("The value of g(x) at x=%0.5f is %0.6f\n",x,gx);
        x=gx;
        gx=-sqrt(pow(e,x)/4);            
    
    }

    printf("The root of the equation is %0.6f\n",gx);

}

    
    
    
