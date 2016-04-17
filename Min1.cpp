#include<iostream>
#define max 20000005

using namespace std;

int dp[max];

int min(int a,int b,int c=10000000) {
	return ((a<b)?((a<c)?a:c):(b<c)?b:c);
}

int main(void) {
	int t,count=0;
	cin>>t;
	dp[1]=0;
	dp[2]=dp[3]=1;
	for(int i=4;i<max;i++){
		int n=i;
		if(n%2!=0 && n%3!=0)	dp[n]=dp[n-1]+1;
		else if(n%2==0 && n%3!=0)	dp[n]=min(dp[n/2],dp[n-1])+1;
		else if(n%3==0 && n%2!=0)	dp[n]=min(dp[n/3],dp[n-1])+1;
		else if(n%2==0 && n%3==0)	dp[n]=min(dp[n/2],dp[n/3],dp[n-1])+1;
	}
	while(t--) {
		count++;
		int num;
		cin>>num;
		cout<<"Case "<<count<<": "<<dp[num]<<"\n";
	}
}
