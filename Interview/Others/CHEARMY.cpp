#include<iostream>
#include<cstdlib>
#include<cmath>
#define llu long long int
using namespace std;

int main(void) {
	int t;
	cin>>t;
	//int def[5] = {0,2,4,6,8};
	while(t--) {
		llu k,temp = 0,power = 0,ans = 0;
		cin>>k;
		temp = k-1;
		while(temp != 0) {
			temp = temp/5;
			power++;
		}
		power--;
		temp = k-1;
		llu count = 0;
		while(count <= power) {
			llu mod = temp % 5;
			llu product = (llu)(pow(10,count) * 2);
			ans += (product*mod);
			//cout<<mod<<product<<ans<<endl;
			count++;
			temp = temp / 5;
		}
		cout<<ans<<endl;
	}
}
