/*****
Name of Author : Gaurav Mitra
*****/
				/*	 Gaussian Jordan Elimination with the provision of Pivot(Slight Change in Gaussian Elimination)	*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>

int main(void) {
	int n;
	printf("Enter the order of the matrix	");
	scanf("%d",&n);
	float arr[n][n+1];	//Augmented Matrix
	double values[n];	// Values are to be stored in this Matrix after computation
	printf("Enter the coefficients of the augmented matrix : ");
	for(int i=0;i<n;i++) {
		for(int j=0;j<=n;j++)
			scanf("%f",&arr[i][j]);
	}
	
	for(int i=0;i<n;i++) {			// Forward Elimination Process
		float piv=0;
		float temp[n+1];
		for(int j=0;j<n;j++) {
			if(i!=j) {
				piv=-(arr[j][i]/arr[i][i]);		// Choosing The Pivot Element
				for(int k=0;k<n+1;k++) {
					temp[k]=arr[i][k]*piv;
				}
				for(int k=i;k<=n;k++)
					arr[j][k]+=temp[k];				//Storing in the Temporary Array
			}	
		}
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<=n;j++)
			printf("%f	",arr[i][j]);
		printf("\n");
	}
	
	for(int i=0;i<n;i++) {
		values[i]=arr[i][n]/arr[i][i];
	}
	printf("Solution to the Above System of Equation is : \n");
	for(int i=0;i<n;i++)
		printf("x[%d] = %0.3f	\n",i+1,values[i]);
	
	
}
