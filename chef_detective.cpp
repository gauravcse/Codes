#include<iostream>
using namespace std;

int main(void) {
	int n;
	cin>>n;
	bool arr[n+1];
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		if(num!=0)
			arr[num-1]=true;
		else
			arr[i]=true;
	}
	for(int i=0;i<n;i++)
		if(arr[i]==false)
			cout<<i+1<<" ";
	cout<<endl;
}

