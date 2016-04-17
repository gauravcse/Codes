
#include<iostream>
using namespace std;

int arr[205];

bool compute(int xorsum,int target,int pos,int n) {
	if(pos<n) {
		if(xorsum==target)
			return true;
		else {
			bool value1=compute(xorsum^arr[pos],target,pos+1,n);
			bool value2=compute(xorsum,target,pos+1,n);
			if(value1==true || value2==true)
				return true;
		}
	}
	else {
		return false;
	}
}

int main(void) {
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cin>>arr[i]	;
	}
	bool value=compute(0,k,0,n);
	if(value==true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
