#include<iostream>
#include<string.h>

using namespace std;

int main(void) {
	int count=0;
	while(1) {
		count++;
		char s[2005];
		gets(s);
		int len=strlen(s);
		if(s[0]=='-')
			break;
		int top=0;
		int ans=0;
		for(int i=0;i<len;i++) {
			char ch=s[i];
			//cout<<s[i]<<"\n";
			if(s[i]=='{') {
				top++;
				//cout<<"Top Status {: "<<top<<"\n";
			}
			else if(s[i]=='}'){
				if(top==0) {	
					if(s[i+1]=='}')  {
						ans+=1;
						i++;
					}
					else if(s[i+1]=='{') {
						ans+=1;
						top++;
					}
				}
				else {
					top--;
				}
			}
		//	cout<<"Top Status : "<<top<<"\n";
		}
		if(top>0) {
			ans+=(top)/2;
		}
		cout<<count<<". "<<ans<<"\n";
	}
}

