#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmpfnc(int i,int j) {
	return (i<j);
}


int main(void) {
	int n;
	cin>>n;
	vector<int> s,lhs,rhs;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		s.push_back(temp);
	}
	vector<int>::const_iterator i,j,k,up,lb;
	for(i=s.begin();i!=s.end();++i) {
		for(j=s.begin();j!=s.end();++j) {
			for(k=s.begin();k!=s.end();++k) {
				lhs.push_back((int)((*i)*(*j)+(*k)));
				if(*i!=0) {
					rhs.push_back((int)((*i)*(*j+*k)));
				}
			}
		}
	}
	int answer=0;
	sort(rhs.begin(),rhs.end(),cmpfnc);
	for(i=lhs.begin();i!=lhs.end();++i) {
		up=upper_bound(rhs.begin(),rhs.end(),*i);
		lb=lower_bound(rhs.begin(),rhs.end(),*i);
		answer+=(up-lb);
	}
	cout<<answer<<endl;
}
