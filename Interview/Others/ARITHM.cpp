#include<iostream>
#define llu long long int

using namespace std;

llu gcd(llu a, llu b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(void) {
	llu t;
	cin>>t;
	//cout<<gcd(21,21);
	while(t--) {
		long long int n,c;
		cin>>n>>c;
		c = c - n;
		if(c == 0) {
			cout<<"No"<<endl;
			continue;
		}
		else if (n <= 2) {
			cout<<"Yes"<<endl;
			continue;
		}
		llu s = 2 * c;
		llu x = n * 2;
		llu y = n * (n - 1);
		//cout<<x<<" "<<y;
		/*if((x == y) && (s % x == 0)) {
			cout<<"Yes"<<endl;
		}*/
		if(s % gcd(x,y) == 0) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
}
