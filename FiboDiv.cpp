#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;

int fibo[31];

void fibonacci() {
	fibo[0]=0;
	fibo[1]=1;
	for(int i=2;i<31;i++)
		fibo[i]=fibo[i-1]+fibo[i-2];
}

int min(int a,int b,int c=INT_MAX) {
	return (a<b?(a<c?a:c):(b<c?b:c));
}

int binSearch(int val) {
	int ub=30;
	int lb=0;
	int mid=-1;
	while(lb<=ub) {
		mid=(ub+lb)/2;
		if(fibo[mid]==val)
			return 0;
		else if(fibo[mid]<val)
			lb=mid+1;
		else if (fibo[mid]>val)
			ub=mid-1;
	}
	if(mid==0) 			return min(abs(fibo[mid]-val),abs(fibo[mid+1]-val));
	else if(mid==30) 	return min(abs(fibo[mid]-val),abs(fibo[mid-1]-val));
	else 				return (min(abs(fibo[mid]-val),abs(fibo[mid-1]-val),abs(fibo[mid+1]-val)));
		
}


int main(void) {
	fibonacci();
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		cout<<binSearch(n)<<endl;
	}
}
