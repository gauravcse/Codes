#include <iostream>
#include<cstdlib>

using namespace std;



int main(void) {
	int t;
	cin>>t;
	while(t--) {
		int n,a,b;
		cin>>n>>a>>b;
		if(a+b-n > 1) {
			cout<<"-1"<<endl;
		}
		else if(a+b-n == 1) {
			for(int i = n-a+1; i <= n; i++) {
				cout<<i<<" ";
			}
			for(int i = n-a; i > n-a-b; i--) {
				cout<<i<<" ";
			}
		}
		else {
			for(int i = n-a+1; i <= n; i++) {
				cout<<i<<" ";
			}
			for(int i = 1; i <= (n-a-b); i++) {
				cout<<i<<" ";
			}
			for(int i = n-a; i > n-a-b; i--) {
				cout<<i<<" ";
			}
			cout<<endl;
		}
	
	}
}
