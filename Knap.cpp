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

int dp[2005][2005];
int max(int a,int b){ 
	return (a>b)?a:b; 
}

int main(void) {
	int s,n;
	int price[n+1];
	int size[n+1];
	scanf("%d %d",&s,&n);
	for(int i=0;i<=s;i++)
		dp[0][i]=0;
	/*for(int i=0;i<=n;i++)
		dp[i][0]=0;*/
	for(int i=1;i<=n;i++) 
		scanf("%d %d",&size[i],&price[i]);
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=s;j++) {
			if(j==0)
				dp[i][j]=0;
			else if(size[i]<=j)
				dp[i][j]=max(dp[i-1][j],price[i]+dp[i-1][j-size[i]]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d\n",dp[n][s]);
	
}
