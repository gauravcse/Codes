#include<iostream>
using namespace std;

int main(void) {
	while(1) {
		unsigned int x,y;
		int l,r;
		cin>>x>>y;
		cin>>l>>r;
		unsigned int temp = (1<<(r)) - 1;
		unsigned int tem = (1<<(l)) - 1;
		unsigned int te = temp ^ tem;
		cout<<temp<<" "<<tem<<" "<<te<<endl;
		unsigned int var = (y & te | x);
		cout<<var<<endl;
		
	}
}
