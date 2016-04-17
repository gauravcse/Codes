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
		double ans=0.0;
		for(count=1;count<=n;count++) {
			double temp=(double)(count+1)/(count+2);
			printf("%f",temp);
			double a=(double)(1/(double)count)*(temp-sum);
			printf("%f",a);
			sum+=(a*(double)count);
			ans+=a;
		}
		printf("%0.11f\n",sum);
	}
}
