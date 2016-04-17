#include<stdio.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int a,b;
		scanf("%d %d",&a,&b);
		printf("\n");
		int min=a<b?a:b;
		if((a%2==0)&&(b%2==0)) {
			if(b!=2*a) {
			  int k=pf(a/2,b);
			  printf("%d",k);
		    }
			else {
				int k=pf(a/2,b);
			  printf("%d",k+1);
			}
		}
		else if(min%2!=0) {
			if(b!=2*a){
		    int k=pfk(a,b);
		    printf("%d",k);
		}
		    else {
		    int k=pfk(a,b);
		    printf("%d",k+1);
			}
	}
	
}
}


