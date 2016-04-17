#include<stdio.h>
#define MOD 1000000007

long long  C(long long  n,long long  k)
{
    long long  ans=1;
    k=k>n-k?n-k:k;
    int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,x;
		long long unsigned m;
		scanf("%d %d &lld",&n,&x,&m);
		long long arr[n+1];
		for(int i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		for(int i=0;i<n;i++)
			printf("%lld	",arr[i]);	
		if(x==1)
			printf("%lld\n",(arr[0])%MOD);
		else {
			long long unsigned sum=arr[x-1];
			for(int i=1;i<x;i++) {
				sum=(sum+(arr[n-i-1]*C(i+m,i))%MOD)%MOD;
			}
			printf("\n%lld\n",sum);
		}
	}
}
