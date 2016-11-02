#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void printNextGreaterElement(vector<int> &arr) {
	stack<int> e;
	e.push(arr[0]);
	for(int i = 1; i < arr.size(); i++) {
		if(e.top() > arr[i])
			e.push(arr[i]);
		else {
			while(!e.empty()) {
				cout<<e.top()<<"->"<<arr[i]<<endl;
				e.pop();
			}
			e.push(arr[i]);
		}
	}
	while(!e.empty()) {
		cout<<e.top()<<"->"<<"-1"<<endl;
		e.pop();
	}
}

int main(void) {	
 	int arr[]= {111, 103, 21, 6};
	vector<int> a(arr,arr+4);
	printNextGreaterElement(a);
}
