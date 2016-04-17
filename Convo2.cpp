#include<iostream>
#include<math.h>

using namespace std;
int main(void) {
	int t;
	cin>>t;
	while(t--) {
		long long int n,s;
		cin>>n>>s;
		s=((n*(n+1))/2)-s;
		if(s==0)
			cout<<"0"<<endl;
		else {
			int count=2;
			int iter=3;
			while(count<s) {
				count+=iter;
				iter++;		
			}
			cout<<(iter-2)<<endl;
		}
		
	}
}
