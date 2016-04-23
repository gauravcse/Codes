#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int fv[n-1];
		int sv[n-1];
		for(int i=1;i<=n-1;i++) 
		    scanf("%d",&fv[i]);
		for(int i=1;i<=n-1;i++) 
		    scanf("%d",&sv[i]);
		int votes[n+1];
		for(int i=1;i<=n;i++) 
		    votes[i]=0;
		for(int i=1;i<n-1;i++) {
			votes[fv[i]]++;
			votes[sv[i]]++;
		}
		int max,maxp,min,minp;
		max=0;maxp=1;min=2*n;minp=1;
		for(int i=1;i<=n;i++) {
			if(max<votes[i])
			    max=votes[i];
			    maxp=i;
			;
			if(min>votes[i]) {
				min=votes[i];
				minp=i;
			}
		}
		devv=votes[i-1];
		amitv=votes[i];
		if(devv==max && amitv==max)||(devv<min && amitv<min) {
			if(devv-max>2) && (amitv-max>2) {
				printf("none");
			}
			else {
				
				}
				
			}
		}
