#include <iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<assert.h>
#include<limits.h>
#include<ctype.h>
#define LOOP for(int i=0;i<n;i++)
#define TEST while(t--)
#define T int t
#define TD scanf("%d",&t)
#define N int n
#define ND scanf("%d",&n)
#define LLU long long unsigned

using namespace std;

int dp[10000];

/*int min(int a,int b) {
	return (a<=b?a:b);
}*/

int piggy(int W,int p[],int w[],int n) {
	if(dp[W]!=INT_MAX) {
		return dp[W];
	}
	LOOP {
		if(W>=w[i])	{
			dp[W]=min(dp[W],piggy(W-w[i],p,w,n)+p[i]);
		}
	}
	return dp[W];
}
int main(void) {
	T;
	TD;
	TEST {
		int e,f;
		scanf("%d %d",&e,&f);
		//assert(e<=10000 && e>=1 && f<=10000 && f>=1 && f>=e);
		int weight=f-e;
		N;
		ND;
		int p[n];
		int w[n];
		LOOP {
			scanf("%d %d",&p[i],&w[i]);
			
		}
		for(int i=0;i<10000;i++)
			dp[i]=INT_MAX;
		int x=piggy(weight,p,w,n);
		for(int i=0;i<100;i++)
			printf("%d  ",dp[i]);
		printf("%d\n",x);
	}
	
}
