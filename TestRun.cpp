#include<stdio.h>
int main() {
	printf("TO PRINT THE SUM OF 1/n n TIMES");
	float sum;
	for(int i=1;i<=500;i++) {
	    for(int j=1;j<=i;j++) {
	    	sum=sum+1/(float)i;
		}
		printf("THE SUM OF 1/%d TAKEN %d TIMES IS %0.5f\n",i,i,sum);
		sum=0.0;
	}
}

