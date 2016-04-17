#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
#define MAX 1000000007
using namespace std;

unsigned long cmpfnc(unsigned long a , unsigned long b) {
	return (a<b);
}

int main(void) {
	int t;
	cin>>t;
	while(t--) {
		bitset<11> s;
		s.reset();
		char ch;
		for(int i=10;i>=0;i--) {
			scanf("%c",&ch);
			if(ch=='w')
				s.set(i,1);
			else
				s.set(i,0);
		
		}	
		unsigned long num=s.to_ulong();
		//cout<<num<<endl;;
		int n;
		cin>>n;
		bitset<11> change[n+1];
		for(int j=0;j<n;j++) {
			for(int i=10;i>=0;i--) {
				scanf("%c",&ch);
				if(ch=='+')
					change[j].set(i,1);
				else
					change[j].set(i,0);
			}
		}
	/*	for(int i=0;i<n;i++) {
			cout<<change[i].to_ulong()<<endl;
		}*/
		vector<unsigned long> arr;
		for(int i=0;i<n;i++) {
			arr.push_back(change[i].to_ulong());
		}
		sort(arr.begin(),arr.end(), cmpfnc);
		unsigned long dp[n+1][num+1];
		dp[0][0]=2;
		
		for(int i=1;i<num+1;i++)
			dp[0][i]=0;
			
			
		int count=1;	
		for(int i=1;i<n+1;i++) {
			if(arr[i]==arr[i-1])
				count++;
			else 
				count=1;
			;
			if(arr[i]==0) {
				dp[i][0]=(2*dp[i-1][0])%MAX;
			}
			else if(arr[i]!=0) {
				if(count==1) {
					dp[i][0]=dp[i-1][0];
				}
				else {
					dp[i][0]=(2*dp[i-1][0])%MAX;
				}
			}
		}
			
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=num;j++) {
				if(arr[i]==j) {
					dp[i][j]=(dp[i-1][j]+1)%MAX;
				}
				else if(arr[i]^j<=num) {
					dp[i][j]=(dp[i-1][arr[i]^j]+dp[i-1][j])%MAX;
				}
				else {
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		cout<<dp[n][num]<<endl;
	}
	
}
