				/* Solving Differential Equations By Modified Eulers Method  */

#include<stdio.h>
#include<math.h>

float f(float x,float y) {
	return (2*x*x+2*y);			// dy/dx = F(x,y)
}

float g(float x) {
	return ((1.5*pow(2.718,2*x)- x*x - x -0.5));		// Analytic Solution of dy/dx = F(x,y)
}


int main(void)	{
	float h;
	printf("Enter the value of the interval Length : \n");		// Interval Length
	scanf("%f",&h);
	float a,b;	//  	Intervals are
	printf("Enter The Intervals : ");
	scanf("%f	%f",&a,&b);
	float x[100],y[100],arr[100];	// Values of x y and a Temporary Matrix
	int i;
	x[0]=0;
	y[0]=1;
	arr[0]=y[0];
	for(i=0;i<(int)((b-a)/h);i++){
		float error=100;
		x[i+1]=x[i]+h;		
		int c=0;
		float slope=f(x[i],y[i]);
		while(error>=0.0001){
			arr[c+1]=y[i]+(h/2)*(slope+f(x[i+1],arr[c]));	// Modified Eulers for Finding the Average Slopes
			error=fabs(arr[c+1]-arr[c]);					
			c++;
		}
		y[i+1]=arr[c];
	}
	printf("Index  | X Computed    | Y Computed | Y Actual | Absolute Error|\n");
	printf("-------------------------------------------------------\n");
	for(i=0;i<11;i++){
	printf("%2d     | %f| %f  |%f | %f      |\n",i,x[i],y[i],g(x[i]),fabs(y[i]-g(x[i])));
	}
	return 0;
}

