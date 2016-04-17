#include<stdio.h>
int product(int a,int b);
int maim(void) {
	int x,n;
	printf("ENTER THE NUMBER AND THE POWER\n");
	scanf("%d %d",&x,&n);
	int result=product(x,n);
	printf("\n%d",result);
}
int product(int a,int b) {
	static int ans=a;
	if(b>0)
	  return ans;
	else {
	  ans=ans*a;
	  product(a,b--);
	}
}
