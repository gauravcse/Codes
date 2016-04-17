                                                /* Computing the root of f(x)=e^x-4x^2 in the Range (4,5) */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define e 2.718281828
#define Fx log(4*x*x)
#define Gx (-sqrt(pow(e,x)/4))
#define Hx (pow(e,x)-4*x*x)
#define Rx (pow(e,x)-8*x)
#define Kx 2/x

int main(void)  {

    /*
     * We will find out the values only if it is non-diverging
     * Firstly we will show that h(x) is diverging
     * Then we will show that f(x) and g(x) are converging and find out the roots
    */
    
    double x=5.0;
    double hx=Hx;
    int iteration=1;      // The iterations
    double previous=0.0;  //The value of the previous iterations
    printf("__________________________________________________________________________________________________________\n\t\t\t\t\t\t\t\t\t\t|\n");
    printf("| | Iteration |\t\t| Xi-1 |\t\t| X |\t\t|Absolute Error|\t\t|f(x)| \n");
    printf("|__________________________________________________________________________________________________________\n\n");
        while((hx-x)>=0.000005 || (hx-x)<=-0.000005) {

     //   printf("The value of h(x) at x=%0.6f is %0.6f\n",x,hx);
        printf("|  |   %d  | \t  |  %0.6f  |\t| %0.6f |         | %0.6f |          | %0.6f |    |\n",iteration++,x,hx,(x-hx),Hx,Rx);
        previous=x;
        x=hx;
        hx=Hx;
        if(x-previous>0) {
            
            printf("The series is diverging and hence we cannot find the root\n");
            break;
        }
    }
 
    x=5.0;
    iteration=1;
    double fx=Fx;
    printf("-_________________________________________________________________________________________________________________________\n");
    printf("|Iteration| \t\t  | Xi-1 |\t          | X |\t\t    |Absolute Error|     \t |f(x)|\t\t|f'(x)|\n");  
    printf("__________________________________________________________________________________________________________________________\n");       

    while((fx-x)>=0.000005 || (fx-x)<=-0.000005) {

        printf("|   %d \t\t         %0.6f \t\t%0.6f \t\t %0.6f \t\t %0.6f \t %0.6f |\n",iteration++,x,fx,(x-fx),Hx,Kx);
    //    printf("The value of f(x) at x=%0.6f is %0.6f\n",x,fx);
        x=fx;
        fx=Fx;
    }
    printf("____________________________________________________________________________________________________________________________\n");
    printf("The root of the equation is %0.6f\n",fx);
    
}    


