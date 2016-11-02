#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
//#include<pair>

using namespace std;

bool cmpfnc(const pair<int,int> &left, const pair<int,int> &right) {
	return left.second > right.second;
}

int main(void) {
	int k,m,n;
	cin>>k>>m>>n;
	map<int,int> freq;
	for(int i = 0; i < n; i++) {
		int val = 0;
		cin>>val;
		if (freq.count(val) > 0) {
			freq[val] = freq[val] + 1;
		}
		else {
			freq[val] = 1;
		}
	}
	vector<pair<int,int> > f(freq.begin(),freq.end());
	sort(f.begin(),f.end(),cmpfnc);
	//cout<<(f.begin())[0]<<endl;
	vector<pair<int,int > > :: iterator it;
	int count = k;
	for(it = f.begin(); it != f.end()  && count > 0; it++,count--) {
		cout<<(*it).first<<endl;
		//<<"->"<<(*it).second<<endl
	}
	
}
