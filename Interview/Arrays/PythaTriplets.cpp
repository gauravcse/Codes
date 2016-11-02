#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isTriplet(vector<int> &arr) {
	sort(arr.begin(),arr.end());
	vector<int> sqarr;
	for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
		sqarr.push_back((*it)*(*it));
	}
	
	for(int i = sqarr.size() - 1; i > 1; i--) {
		int sum = sqarr[i];
		int start = 0,end = i - 1;
		int oursum = 0;
		//cout<<sum<<" : ";
		while(start < end) {
			oursum = sqarr[start] + sqarr[end];
		//	cout<<oursum<<" ";
			if(oursum  == sum)
				return true;
			else if (oursum < sum)
				start++;
			else if(oursum > sum)
				end--;
		}
		//cout<<endl;
	}
	return false;
}


int main(void) {	
	int arr[] = {3, 10, 4, 6, 5, 8, 9};
    vector<int> num(arr,arr+7);
    isTriplet(num)? cout << "Yes": cout << "No";
    return 0;
}
