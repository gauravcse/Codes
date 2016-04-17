#include<stdio.h>
int revsum(int a);
int main() {
	int n;
	scanf("%d",&n);
	while(n--)  {
		int x,y;
		scanf("%d %d",&x,&y);
		int rev=revsum(revsum(x)+revsum(y));
		printf("%d\n",rev);
	}
}
int revsum(int a) {
	int reverse=0;
	while(a%10==0) {
			a/=10;
	}
	while(a>0) {
		
	    reverse=(10*reverse)+(a%10);
		a/=10;	
	}
	return reverse;
}
