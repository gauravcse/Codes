#include<stdio.h>

int main(void) {
	int t,count=0;
	scanf("%d",&t);
	while(t--) {
		count++;
		long long unsigned n,k;
		scanf("%llu %llu",&n,&k);
		long long unsigned i=1,j=1;
		do{
			if((int)(n+i)==(int)(n^i)) {
				j++;
				//printf("%llu	%llu\n",(n+i),(n^i));
			}
			i++;
		}while(j<=k);
		printf("Case #%d: %llu\n",count,--i);
	}
}
