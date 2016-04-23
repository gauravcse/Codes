#include<stdio.h>
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		if(n<=3)
		    printf("%d\n",0);
		else {
			n=n-3;
			int k=1;
			int count=2;
			while(n--) {
				if(n==0) {				
				    printf("%d\n",k);
				    break;
				}
				--n;
			    if(n==0) {
			    	printf("%d\n",k);
			    	break;
			    }
			    else {
			 	k=k+count;
			    	count++;
			    }
		    }
		}
	}
}

