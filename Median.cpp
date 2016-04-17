#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#define LOOP for(int i=0;i<n;i++)
#define TEST while(t--)
#define T int t
#define TD scanf("%d",&t)
#define N int n
#define ND scanf("%d",&n)
#define LLU long long unsigned

int main(void) {
	N;
	ND;
	int priority[n+1];
	for(int i=1;i<=n;i++) {
		int number;
		scanf("%d",&number);
		priority[i]=number;
		int j=i/2;
		int pi=i;
		while(j>=0 && priority[j]>priority[pi] && pi>1) {
			priority[pi]=priority[j];
			priority[j]=number;
			pi=j;
			j=j/2;
		}
		//for(int j=1;j<=i;j++)
		//	printf("%d	",priority[j]);
		printf("\n");
		if(i%2==0){
			float ans=priority[i/2]+priority[(i/2)+1];
			ans=ans/2.0;
			printf("%0.1f\n",ans);
		}
		else if(i%2!=0){
			float ans=priority[i/2+1];
			printf("%0.1f\n",ans);
		}
	}
}
