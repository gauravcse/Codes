#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long int n;
		scanf("%lld",&n);
		if(n==1) {
			printf("1 0\n");
			continue;
		}
		else if(n==2) {
			printf("1 2\n");
			continue;
		}
		else if(n==3){
			printf("-2 2\n");
			continue;
		}
		else if(n==4) {
			printf("-2 -2\n");
			continue;
		}
		long long int k=(n/4);
		long long int x,y;
		x=y=0;
		long long int positive_x=(k*(2*k+3))+1;
		long long int negative_x=-(k*(2*k+1));
		x=positive_x+negative_x;
		long long int positive_y=(2*k*k);
		long long int negative_y=-(2*k*(k+1));
		y=positive_y+negative_y;
		if(n%4==1) {
			printf("%lld %lld\n",x,y);
		}
		else if(n%4==2) {
			printf("%lld %lld\n",x,(y+n));
		}
		else if(n%4==3) {
			printf("%lld %lld\n",(x-n),(y+n-1));
		}
		else {
			printf("%lld %lld\n",(x-n-1),(y));
		}
	}
}
