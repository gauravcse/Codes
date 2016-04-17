#include<stdio.h>
int main() {
	int n;
	printf("ENTER THE NUMBER OF LINES\n");
	scanf("%d",&n);
	printf("\n");
	int x,y;
	for(x=(n-1);x>=0;x--) {
		for(y=1;y<=x;y++)
		  printf(" ");
	    int t=n-x;
	    for(y=1;y<=(2*t-1);y++)
	      printf("*");
	    printf("\n");
	}
	
}
