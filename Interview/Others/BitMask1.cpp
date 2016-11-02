#include<iostream>
#include<cstdlib>

using namespace std;

int pairAndSum(int *arr,int len) {
	int sum[len + 1],total = 0;
	for(int i = 1; i < len ; i++) {
		total += arr[i];
	}
	sum[0] = total;
	for(int i = 1; i < len ; i++) {
		sum[i] = sum[i - 1] - arr[i] ;
	}
	int ans = 0;
	for(int i = 0; i < len ; i++) {
		//cout<<sum[i]<<" ";
		ans += (sum[i] & arr[i]);
	}
	return ans;
}

int main(void) {
	int arr[] = {5,10,15};
    int n = sizeof(arr) / sizeof (arr[0]);
    cout << pairAndSum(arr, n) << endl;
    return 0;
}
