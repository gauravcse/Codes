#include<iostream>
#define llu long long int
#define MAX 1000000007

using namespace std;

int main(void) {
	int t;
	cin>>t;
	while(t--) {
		llu n,k;
		cin>>n>>k;
		llu arr[n+1];
		for(int i = 0; i < n;i++) {
			llu num;
			cin>>num;
			if(num >= 0)
				arr[i] = num;
			else
				arr[i] = MAX + num;
		}
		//cout<<(-8%MAX)<<endl;
		llu dp[k+1][n+1];
		
		/*for(int i = 0; i <= n ; i++) {
			dp[0][i] = INT_MIN;
		}
		for(int i = 0; i <= k ; i++) {
			dp[i][0] = INT_MIN;
		}*/
		for(int i = 0 ; i <= k; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j]= 0;
			}
		}
		for(int i = 1; i <= n; i++) {
				dp[1][i] = arr[i-1];
		}
		for(int j = 1; j <= k; j++){
			dp[j][1] = arr[0];
		}
		/*for(int i = 0 ; i <= k; i++) {
			for (int j = 0; j <= n; j++) {
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}*/
		if(k == 1) {
			cout<<dp[1][n]<<endl;
			continue;
		}
		else {
			for(int i = 2; i <= k; i++) {
				for(int j = 2; j <= n ; j++) {
					dp[i][j] = max((dp[i-1][j-1]*arr[j-1])%MAX,dp[i][j-1]);
				}
			}
		}
		for(int i = 0 ; i <= k; i++) {
			for (int j = 0; j <= n; j++) {
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		
		//cout<<dp[n][k]<<endl;
	}
}
