#include<iostream>
using namespace std;
int main(void) {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		if(n<=6) {
			cout<<"-1"<<endl;
			continue;
		}
		else {
			cout<<n<<endl;
			for(int i=1;i<n;i++) {
				cout<<i<<" "<<i+1<<endl;
			}
			cout<<n<<" 2"<<endl;
			cout<<"3"<<endl;
		}
	}
}
