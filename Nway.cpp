#include<iostream>

using namespace std;

int main(void) {
	int n;
	cin>>n;
	int dp[n+1];
	dp[0]=0;
	dp[1]=dp[2]=dp[3]=1;
	for(int i=2;i<=n;i++) {
		int max=0;
		for(int j=1;j<=3;j++) {
			int temp=0;
			for(int k=0;k<i;k++) {
				if((j+dp[k])==i) {
					temp=dp[k];
					break;
				}
			}
			max+=temp;
		}
		dp[i]=max;
	}
	cout<<dp[n];
}
