#include<stdio.h>
int product(int a,int b);
int main(void) {
	int x,n;
	printf("ENTER THE NUMBER AND THE POWER\n");
	scanf("%d %d",&x,&n);
	int result=product(x,n);
	printf("\nTHE POWER OF %d RAISED TO %d IS %d ",x,n,result);
}
int product(int a,int b) {
	if(b==0)
      return 1;
	else {
      return (a*(product(a,b-1)));
	}
}
