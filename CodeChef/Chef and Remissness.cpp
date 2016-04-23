#include<stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int a,b;
		scanf("%d %d",&a,&b);
		int min=a>=b?a:b;
		int max=a+b;
		printf("%d %d\n",min,max);
	}
}
