#include<stdio.h>
int main(void) {
	long long unsigned t;
	scanf("%llu",&t);
	while(t--) {
		long long unsigned k;
		scanf("%llu",&k);
		printf("%llu\n",(192+(250*(k-1))));
	}
}
