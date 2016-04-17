							/* Lagrange Interpolation */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>

int main(void) {
	int n;
	printf("Enter the value of number of Table Values : ");
	scanf("%d",&n);
	double arr[n][2];
	printf("Enter The Table Values of X and Y in Order : \n");
	for(int i=0;i<n;i++) {
+		scanf("%lf%lf",&arr[i][0], &arr[i][1]);
	}
	printf("Enter the value for which The InterPolation is to be done : \n");
	double x;
	scanf("%lf",&x);
	double sum = 0;
	for(int i=0;i<n;i++) {
		double num = 1.0;		// Numerator
		double den = 1.0;		// Denominator
		for(int j=0;j<n;j++) {
			if(i==j){
			}
			else {
				num*=(x-arr[j][0]);
				den*=(arr[i][0]-arr[j][0]);
			}
		//	printf("Product after each step : %lf	%lf\n",num,den);
		}
		sum+=(arr[i][1]*(num/den));
		//printf("Sum at this step : %lf",sum);
	}
	printf("Extrapolated Value is Y =  %0.6lf",sum);
}
