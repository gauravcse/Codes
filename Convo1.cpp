#include<iostream>

using namespace std;

int main(void) {
	int t;
	cin>>t;
	while(t--) {
		long long int b,w,x,y,z,ans=0;
		cin>>b>>w;
		cin>>x>>y>>z;
		if(x<=y) {
			ans+=x*b;
			if(w*y<=w*(x+z))
				ans+=w*y;
			else
				ans+=w*(x+z);
		}
		else {
			ans+=y*w;
			if(x*b<=b*(z+y))
				ans+=x*b;
			else
				ans+=b*(y+z);
		}
		cout<<ans<<endl;
	}
}
