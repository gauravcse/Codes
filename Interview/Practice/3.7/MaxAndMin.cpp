#include<iostream>
#include<vector>
using namespace std;

pair<int,int> maxmin(vector<int> &arr,int low,int high) {
	if(low == high) {
		pair<int,int> m (arr[low],arr[high]);
		return m;
	}
	else if(low + 1 == high) {
		pair<int,int> m ((arr[low] > arr[high] ? arr[high] : arr[low]),(arr[low] > arr[high] ? arr[low] : arr[high]));
		return m;
	}
	else {
		int mid = (low + high)/2;
		pair<int,int> left,right;
		left = maxmin(arr,low,mid);
		right = maxmin(arr,mid + 1,high);
		int mini = 0,maxi = 0;
		mini = left.first < right.first ? left.first : right.first;
		maxi = left.second < right.second ? right.second : left.second;
		pair<int,int> mm(mini,maxi);
		return mm;
	}	
}

int main(void) {
	int arr[] = {1000, 11, 445, 5, 330, 4050, 1256, -55};
	vector<int>  a(arr,arr+8);
	pair<int,int> ans = maxmin(a,0,7);
	cout<<"MIN : "<<ans.first<<endl<<"MAX : "<<ans.second<<endl;
}
