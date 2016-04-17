#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
//#define INT_MAX 999999999

int main(void) {
	int n,count=0;
	cin>>n;
	vector<int> arr;
	//vector<int>sum;
	int k;
	for(int i=0;i<n;i++) {
		cin>>k;
		arr.push_back(k);
	}
	sort(arr.begin(),arr.end());
	reverse(arr.begin(),arr.end());
	int area=INT_MAX;
	for(vector<int>::iterator iter=arr.begin();iter!=arr.end(); iter++) {
		count++;
		if(count==1) {
			area=*iter;
	//		sum.push_back(*iter);
			continue;
		}
		//cout<<sum[count-2]<<endl;
	//	sum.push_back(sum[count-2]+*iter);
	/*	if((arr[count-1]*count)<area) {
			break;
		}
		else {*/
			int newarea=arr[count-1]*count;
			if(newarea>area)
				area=newarea;
	//	}
		//cout<<area<<endl;
	}
	cout<<area<<endl;
}
