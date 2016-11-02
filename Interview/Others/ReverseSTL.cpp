#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void reverseWord(string &str) {
	reverse(str.begin(),str.end());
}

string reverse(string &inp) {
	inp += " ";
	string word = "";
	string out = "";
	int count = 0;
	for(int i = 0; i < inp.size(); i++) {
		if((inp[i] >= 65 && inp[i] <= 90) || (inp[i] >= 97 && inp[i] <= 122)) {
			word += inp[i];
		}
		else {
			reverseWord(word);
			out += word;
			word = "";
			out += inp[i];
		}
	}
	return out; 
}

int main(void) {
	string str;
	getline(cin,str);
	//cout<<str;
	string out = reverse(str);
	cout<<out;
}
