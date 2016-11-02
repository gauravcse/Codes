#include<iostream>

using namespace std;

int getSetBits(unsigned int n) {
	int it = 0;
	while(n) {
		n = n & (n-1);
		it++;
	}
	return it;
}

int getDiff(unsigned int n, unsigned int m) {
	unsigned int change = n ^ m;
	return getSetBits(change);
}

int main(void) {
	unsigned int n,m;
	cin>>n>>m;
	cout<<"Bit Difference : "<<getDiff(n,m)<<endl;
}
