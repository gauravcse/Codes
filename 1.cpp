#include<stdio.h>
int main(void) {
	int t;
	scanf("%d",&t);
	printf("\n");
	while(t--) {
		long int n;
		scanf("%ld",&n);
		printf("\n");
		long int count;
		double sum=0.0;
		//double ans=0.0;
		for(count=1;count<=n;count++) {
		   double k=count;
		   sum+=((k+1)/(k+2))-(1/k+1);
		}
		printf("%0.11f\n",sum);
}
}
