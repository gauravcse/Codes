#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

string printName(int n) {
	string ans;
	while(n) {
		int mod = n % 26;
		n /= 27;
		if (mod == 0)
			ans.insert(0,"Z");
		else {
			char *c = (char*)malloc(sizeof(char));
			c += (char)(mod + 65);
			string temp = c;
			ans.insert(0,temp);
		}
	}
	return ans;
}

int main(void) {
	int n;
	cin>>n;
	cout<<printName(n)<<endl;
}
