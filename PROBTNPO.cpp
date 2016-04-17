#include<stdio.h>
#include<math.h>
#define max 1000005

int dp[max];

int cycle(long long unsigned n,int count) {
	if(n<max) {
		if(dp[n]!=-1)
			return (count+dp[n]-1);
		else {
			if(n%2==0)	cycle(n/2,count+1);
			else		cycle(3*n+1,count+1);
		}
	}
	else {
		if(n&(n-1)) return (count+(int)((log(n)/log(2)))-1);
		else if(n%2==0)	cycle(n/2,count+1);
		else 			cycle(3*n+1,count+1);
	}
}

int main(void) {
	int a,b;
	for(int i=0;i<max;i++)
		dp[i]=-1;
	dp[1]=1;
	dp[2]=2;
	int i=2;
	while(2*i<max) {
		dp[i]=dp[i/2]+1;
		i=2*i;
	}
	for(long long unsigned j=3;j<1000005;j++) {
		int count=cycle(j,1);
		dp[j]=count;
	}
	/*for(i=1;i<100;i++)
		printf("%d  %d\n",i,dp[i]);*/
	while(scanf("%d %d",&a,&b)!=EOF)  {
		if(a>b) {
			printf("%d %d\n",a,b);
		}
		else if(a==b) {
			printf("%d %d %d\n",a,b,dp[a]);
		}
		else {
			int maxi=dp[a];
			for(i=a+1;i<=b;i++){
				if(dp[i]>maxi)
					maxi=dp[i];
			}
			printf("%d %d %d\n",a,b,maxi);
		}
	}
}
