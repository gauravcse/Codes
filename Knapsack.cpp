#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n,m;
	scanf("%d %d",&n,&m);
	int count=0;
	while(m>0) {
		if(n<=m) {
			m=m-n;
			n--;
			count++;
			continue;
		}
		n--;	
	}
	if(m<0) {
		printf("-1");
	}
	else {
		printf("%d",count);
	}
}
