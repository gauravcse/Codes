#include<iostream>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<vector>

using namespace std;

vector<int> convert(int n) {
	vector<int> num;
	while(n > 0) {
		num.insert(num.begin(), n % 10);
		n /= 10;
	}
	return num;
}

int toDigit(vector<int> &n ) {
	int num = 0,count = n.size() - 1;
	while(count >= 0) {
		num += (n[count]*(int)pow(10,count));
		count --;
	}
	return num;
}

int nextPerm(vector<int> &n) {
	int i = n.size() - 1;
	queue<int> temp;
	for(; i > 0; i--) {
		if(n[i] > n[i - 1]) {
			break;
		}
		else {
			temp.push(n[i]);
		}
	}
	//cout<<endl<<i<<endl;
	if(!temp.empty()) {
		n[i] = n[i - 1];
		n[i-1] = temp.front();
		temp.pop();
	}
	while(!temp.empty()) {
		i++;
		n[i] = temp.front();
		cout<<temp.front()<<" ";
		temp.pop();
	}
	return toDigit(n);
}


int getNextHighDigit(int n) {
	vector<int> vec(convert(n));
	cout<<endl<<"Next Digit : "<<nextPerm(vec)<<endl;
}

int main(void) {
	getNextHighDigit(534976);
}
