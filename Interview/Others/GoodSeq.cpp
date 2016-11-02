#include<bits/stdc++.h>
#define min(a,b) (a < b ? a : b)
using namespace std;

int getGoodSequence(vector<int> &arr) {
	int n = arr.size();
	set<int> unique;
	for(int i = 0; i < n; i++)
		unique.insert(arr[i]);
	queue<int> q;
	int max_len = INT_MAX;
	map<int,int> m;
	int i = 0;
	while(i < n) {
		q.push(arr[i]);
		if(m.find(arr[i]) == m.end())
			m[arr[i]] = 1;
		else
			m[arr[i]] = m[arr[i]] + 1;
		;
		if(m.size() == unique.size()) {
			max_len = min(q.size(),max_len);
			//cout<<q.size()<<"\t";
			while(true) {
				if(m[q.front()] > 1) {
					m[q.front()] = m[q.front()] - 1;
					//cout<<q.front()<<" ";
					q.pop();
				}
				else
					break;
			}
			max_len = min(q.size(),max_len);
		}
		i++;
	}
	for(set<int>::iterator it = unique.begin(); it != unique.end(); it++) 
		cout<<(*it)<<" ";
	cout<<m.size()<<"    ";
	return max_len;
}


int main(void) {
	int arr[] = {1,1,2,2,3,3,4,4,5,5};
	vector<int> a(arr,arr + 10);
	cout<<getGoodSequence(a);
}
