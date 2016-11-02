#include<iostream>

using namespace std;

int arrayIGreaterJ(int *arr,int i,int j) {
	if(j < i || j < 0 || i >= sizeof(arr)/sizeof(int)) {
		return 0;
	}
	else if(arr[j] > arr[i]) {
		return  (j-i);
	}
	else {
		return max(arrayIGreaterJ(arr,i+1,j),arrayIGreaterJ(arr,i,j-1));
	}
}

int main(void) {
	int arr[] = {8,7,9,3,4,0,1};
	cout<<arrayIGreaterJ(arr,0,6);
}
