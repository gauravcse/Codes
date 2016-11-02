#include<iostream>
#include<string>
#include<algorithm>
#include<cstddef>

using namespace std;

void reverseString(string &test) {
	int l = test.size();
	string rev("");
	int temp = 0;
	while((temp = test.find_first_of(" ")) != string::npos) {
		string data = test.substr(0,temp + 1);
		test = test.substr(temp + 1,l);
		reverse(data.begin(),data.end());
		rev.insert(0,data);
	}
	rev.erase(rev.begin(), find_if(rev.begin(), rev.end(), not1(ptr_fun<int, int>(isspace))));
	cout<<rev;
}

int main(void) {
	string test = "Hello world this is Gaurav";
	reverseString(test);
}
