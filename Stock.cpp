#include<iostream>

using namespace std;

int n;

int max(int a,int b,int c) {
	return (a>b?(a>c?a:c):(b>c?b:c));
}

int maximise(int arr[],int i,int sale,int units,int buy) {
	if(i==n-1){
		return (arr[i]*units-buy)+sale;
	}
	else {
		return max(maximise(arr,i+1,sale,units+1,buy+arr[i]),maximise(arr,i+1,sale,units,buy),maximise(arr,i+1,(arr[i]*units-buy)+sale,0,0));
	}
}


int main(void) {
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int max_stock=maximise(arr,0,0,0,0);
		cout<<max_stock<<endl;
	}
}
