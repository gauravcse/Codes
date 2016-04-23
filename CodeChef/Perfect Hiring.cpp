#include<stdio.h>
#include<stdlib.h>
int main(void) {
	long long unsigned n,p,x;
	scanf("%llu %llu %llu",&n,&p,&x);
	long long unsigned a[n+1];
	for(long long unsigned i=1;i<=n;i++) {
		scanf("%llu",&a[i]);
	}
	long long unsigned pa[n+1];
	for(long long unsigned i=1;i<=n;i++) {
		if(i!=1) {
		    p=p-x;
		}
		pa[i]=a[i]*p;
	}
	long long unsigned max=pa[1];
	long long unsigned pos=1;
	for(long long unsigned i=2;i<=n;i++) {
		if(pa[i]>=max) {
		    pos=i;
		    max=pa[i];
		}
	}
	printf("%llu",pos);
}
