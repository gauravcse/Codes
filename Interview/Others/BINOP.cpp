#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int main(void) {
	int t;
	cin>>t;
	while(t--) {
		int ans = 0;
		char a[100005],b[100005];
		scanf("%s",a);
		scanf("%s",b);
		cin>b;
		int len = strlen(a);
		int differa1 = 0,differa0 = 0;
		int aone = 0,bone = 0,azero = 0,bzero = 0;
		for (int i=0; i < len; i++) {
			if(a[i] == '1') {
				aone++;
			}
			else {
				azero++;
			}
			if(b[i] == '1') {
				bone++;
			}
			else {
				bzero++;
			}
			if(a[i] == '0' && b[i] == '1') {
				differa0++;
			}
			else if(a[i] == '1' && b[i] == '0') {
				differa1++;
			}
		}
		//cout<<aone<<azero<<bone<<bzero;
		if((azero == 0 && bzero == 0) || (aone == 0 && bone == 0)) {
			cout<<"Lucky Chef"<<endl<<0<<endl;
		}
		else if ((azero == 0 && bzero != 0) || (aone == 0 && bone != 0)) {
			cout<<"Unlucky Chef"<<endl	;
		}
		else {
			cout<<"Lucky Chef"<<endl<<min(differa0,differa1) + abs(aone - bone)<<endl;
		}

	}
	return 0;
}
