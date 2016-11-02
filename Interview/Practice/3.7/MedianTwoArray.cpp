#include<iostream>
#include<vector>
#include<stack>
using namespace std;

float getMedian(vector<int> &arr1,vector<int> &arr2,int l1,int h1,int l2,int h2) {
	if(((l1 + 1) == h1) && ((l2 + 1) == h2)) {
		return ((max(arr1[l1],arr2[l2])) + (min(arr1[h1],arr2[h2])) / 2.0);
	}
	else {
		int mid1 = (l1 + h1) / 2;
		int mid2 = (l2 + h2) / 2;
		if(arr1[mid1] == arr2[mid2])	
			return arr1[mid1];
		else if(arr1[mid1] > arr2[mid2]) {
			return getMedian(arr1,arr2,l1,mid1 + 1,mid2 - 1,h2);
		}
		else {
			return getMedian(arr1,arr2,mid1 - 1,h1,l2,mid2 + 1);
		}
	}
}

int main(void) {	
 	int arr1[]= {1,2,3,4,5};
 	int arr2[]= {4,5,6,7,8};
	vector<int> a(arr1,arr1 + 5);
	vector<int> b(arr2,arr2 + 5);
	cout<<"Median : "<<getMedian(a,b,0,5,0,5);
	
}
