#include<iostream>
#include<cstdlib>
#define INF -999999

using namespace std;

int main(void) {
	int n;
	cin>>n;
	int winner = -1;
	int one = 0,two = 0;
	int max_lead = INF;
	while(n--){
		int p1 , p2;
		cin>>p1>>p2;
		one += p1;
		two += p2;
		int lead = abs(one - two);
		if (lead > max_lead) {
			if(p1 > p2){
				max_lead = lead;
				winner = 1;
			}
			else {
				max_lead = lead;
				winner = 2;
			}
		}
	}
	cout<<winner<<" "<<max_lead<<endl;
}
