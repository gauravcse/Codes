#include<bits/stdc++.h>
using namespace std;

unsigned int powerOfTwo(unsigned int n) {
	if(n & !(n&(n-1))) {
		return n;
	}
	else {
		n--;
		n = n | n >> 1;
		n = n | n >> 2;
		n = n | n >> 4;
		n = n | n >> 8;
		n = n | n >> 16;
		n = n | n >> 32;
		return ++n;
	}
}

int main(void) {
	while(1) {
		cout<<"Enter A Number : ";
		unsigned int n;
		cin>>n;
		cout<<"Next Power of 2 is : "<<powerOfTwo(n)<<endl;
	}
}
