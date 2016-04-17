                                /* Newton Raphson Equations for Solving Simultaneous Equations*/

#include<stdio.h>
#include<math.h>


double f1(double x,double y) {
    return (x*x+x*y-10);            //First Function
}



double f2(double x,double y) {
    return (y+3*y*y*x-57);      //Second Function
}


double df1x(double x,double y){
	return(2*x+y);              //Differentiation of First Function with respect to x
}


double df2x(double x,double y){
	return(3*y*y);              //Differentiation of Second Function with respect to x            
}


double df1y(double x){
	return(x);                  //Differentiation of First Function with respect to y
}


double df2y(double y,double x){
	return(1+6*x*y);            //Differentiation of Second Function with respect to y
}


double determinantJ(double x,double y){
	double detValue;
	detValue=df1x(x,y)*df2y(y,x)+df2x(x,y)*df1y(x);
	return(detValue);
}



void print_sol(double x,double y) {
    printf("THE SOLUTION IS :\nx=%0.4f\ny=%0.4f\n",x,y);        // Prints final Solution
}


void print_step(double x0,double y0,double x1,double y1){
    printf("Old Vaule of x=%0.4f and y=%0.4f \n",x0,y0);
    printf("New Vaule of x=%0.4f and y=%0.4f \n\n",x1,y1);
}


double newValueOfX(double x,double y){
	double x1;
	x1=df2y(y,x)*f1(x,y)-df1y(x)*f2(x,y);
	return(x1/determinantJ(x,y));
}

double newValueOfY(double x,double y){
	double y1;
	y1=-df2x(x,y)*f1(x,y)+df1x(x,y)*f2(x,y);
	return(y1/determinantJ(x,y));
}


int main(void){
	double tempx,tempy,x0,y0,x1,y1;
	x1=0.1;
	y1=0.5;
	do{
		x0=x1;
		y0=y1;
		x1=x0-newValueOfX(x0,y0);
		y1=y0-newValueOfY(x0,y0);
		print_step(x0,y0,x1,y1);
	}while(fabs(x0-x1)>=0.0001||fabs(y0-y1)>=0.0001);
	print_sol(x1,y1);
	return(0);
}
