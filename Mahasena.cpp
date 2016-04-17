#include<iostream>
using namespace std;
int main(void) {
	int n,even=0,odd=0;
	cin>>n;
	for(int i=0;i<n;i++) {
		int t;
		cin>>t;
		if(t&1)
			odd++;
		else
			even++;
	}
	if(even>odd)
		cout<<"READY FOR BATTLE"<<endl;
	else
		cout<<"NOT READY"<<endl;
}
