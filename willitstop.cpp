#include<iostream>

using namespace std;

int main(void) {
	long long unsigned n;
	cin>>n;
	if(!(n&(n-1)))
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;
}
