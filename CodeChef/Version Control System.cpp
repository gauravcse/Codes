#include<stdio.h>
int main(void) {
	int ignored[101];
	int tracked[101];
	int t;
	scanf("%d",&t);
	while(t--) {
		int m,k,n;
		scanf("%d %d %d",&n,&m,&k);
		for(int i=1;i<101;i++)
		    ignored[i]=tracked[i]=0;
		while(m--) {
			int l;
			scanf("%d",&l);
			ignored[l]++;
		}
		while(k--) {
			int l;
			scanf("%d",&l);
			tracked[l]++;
		} 
		int both=0;
		int none=0;
/*		for(int i=1;i<101;i++) {
			if(ignored[i]!=1)
			    ignored[i]=0;
			if(tracked[i]!=1)
			    tracked[i]=0;
		}*/
		for(int i=1;i<=n;i++) {
			if((ignored[i]==1)&&(tracked[i]==1))
			  both++;
			else if((ignored[i]==0)&&(tracked[i]==0))
			  none++;
		}
		printf("%d %d\n",both,none);
	}
}
