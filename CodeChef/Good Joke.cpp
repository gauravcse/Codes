#include<stdio.h>
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int result=0;
		for(int i=1;i<=n;i++)  {
			int p,q;
			scanf("%d %d",&p,&q);
		}
		for(int i=1;i<=n;i++)
		    result^=i;
		printf("%d\n",result);
	}
}
