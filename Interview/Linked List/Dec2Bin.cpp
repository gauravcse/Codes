#include<iostream>
#include<cstdlib>
#include<list>
using namespace std;

int convertDec(list<bool> &ll) {
	int dec = 0;
	for(list<bool>::iterator it = ll.begin(); it != ll.end(); ++it) {
		dec <<= 1;
		if(*it)
			dec += 1; 
	}
	return dec;
}

int main(void) {
	list<bool> linklist;
	linklist.push_back(1);
	linklist.push_back(1);
	linklist.push_back(1);
	cout<<"Decimal Value : "<<convertDec(linklist)<<endl;
}
