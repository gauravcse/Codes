#include<iostream>
#include<cstring>
using namespace std;

int main(void) {
	int t;
	cin>>t;
	while(t--)	 {
		char str[3000000];
		cin>>str;
		int len=strlen(str);
		if(len==1) {
			cout<<"YES"<<endl;
			continue;
		}
		if(len%2==0) {
			int flag=0;
			for(int i=0;i<len/2;i++) {
				if(str[i]!=str[i+(len/2)]) {
					flag=1;
					break;
				}
			}
			if(flag)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
		else {
			int flag=0;
			int number_of_mismatch1=0;
			int number_of_mismatch2=0;
			for(int i=0;i<=(len/2);i++) {
				/*if(number_of_mismatch <= 1 && (len/2 + i +1)< len && str[i+number_of_mismatch]!=str[len/2+i+1]) {
					number_of_mismatch++;
					
				}*/
				//cout<<str[i]<<"\t"<<str[len/2+i+1]<<endl;
				if(str[i]!=str[len/2+i+1]) {
					for(int j=i+1;j<=(len/2);j++) {
						if(j<len/2 && str[j]!=str[len/2 + j])  {
							number_of_mismatch1=1;
							break;
						}
					}
					if(number_of_mismatch1)
						break;
					else
						continue;
				}
			}
			for(int i=0;i<(len/2);i++) {
				if(str[i]!=str[len/2+i]) {
					for(int j=i+1;j<(len/2);j++) {
						if(str[j-1]!=str[len/2 + j])  {
							number_of_mismatch2=1;
							break;
						}
					}
					if(number_of_mismatch2)
						break;
					else
						continue;
				}
			}
			if(number_of_mismatch1==1 && number_of_mismatch2==1) {
				cout<<"NO"<<endl;
			}
			else {
				cout<<"YES"<<endl;
			}
		}
	}
}
