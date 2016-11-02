#include<iostream>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<vector>

using namespace std;

void spiralMatrix(int arr[][6]) {
	int rows = 3;
	int l = 0,r = 5,t = 0,b = rows - 1,tot = 18,i = 1;
	while(i <= tot) {
		for(int j = l; j <= r; j++) {
			cout<<arr[t][j]<<" ";
			i++;
		}
		t++;
		if(i > tot)	break;
		for(int j = t; j <= b; j++) {
			cout<<arr[j][r]<<" ";
			i++;
		}
		r--;
		if(i > tot)	break;
		for(int j = r; j >= l; j--) {
			cout<<arr[b][j]<<" ";
			i++;
		}
		b--;
		if(i > tot)	break;
		for(int j = b; j >= t; j--) {
			cout<<arr[j][l]<<" ";
			i++;
		}
		if(i > tot)	break;
		l++;
	}
}

int main(void) {
	int a[3][6] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
    spiralMatrix(a);
}
