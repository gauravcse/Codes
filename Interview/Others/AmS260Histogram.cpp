/*	MAX AREA IN A HISTOGRAM	*/
#include<iostream>
using namepsce std;

int main(void) {
	int n,i = 0;
	cin>>n;
	int arr[n];
	while(i < n) {
		cin>>arr[i];
		i++;
	}
	cout<<max_area(arr);
}

int max_area(int arr[]) {
	int min_pos = minimum(arr);
	return divide_conquer(arr,min_pos,min_pos-1,sizeof(arr)/sizeof(int)-min_pos-1);
}


int divide_conquer(int arr[],int pos,int left,int right) {
	if(left == right) {
		return max(arr[0],arr[])
	}
}

