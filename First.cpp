#include<iostream>

using namespace std;

class List {
	public :
			int value;
			List();
};

List::List() {
	cout<<"This is a list"<<"\n";
}

int main(void) {
	List list1;
	List list2;
	list1.value=5;
	list2.value=10;
	cout<<"List 1 has value "<<list1.value<<"\n List 2 has value "<<list2.value;
}
