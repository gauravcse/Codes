#include <iostream>
#include<string.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	outside :while(t--) {
	    char s1[1005],s2[1005];
	    cin>>s1;
	    cin>>s2;
	    bool outer_flag=false;
	    for(int i=97;i<=122;i++) {
	        char ch=(char)i;
	        bool flag=false;
	        for(int i=0;i<strlen(s1);i++) {
	            if(ch==s1[i]) {
	                flag=true;
	                break;
	            }
	        }
	        if(flag) {
	            for(int i=0;i<strlen(s2);i++) {
    	            if(ch==s2[i]) {
    	                outer_flag=true;
    	                cout<<"Yes"<<endl;
    	                goto outside;
    	            }
	            }
	        }
	    }
	    if(!outer_flag)
	        cout<<"No"<<endl;
	    
	}
	return 0;
}

