#include <iostream>
#include<cstdlib>
#define MIN -999999999999
using namespace std;
typedef long long int LLU;

LLU max(LLU aplus,LLU aminus) {
    if(aplus>=aminus ) 
        return aplus;
    else if(aminus>=aplus)
        return aminus;
}

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        int pos=-1;
        LLU overall_max=MIN;
        int a[n+1];
        int b[n+1];
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        /*for(int i=0;i<n;i++) {
            cout<<a[i]<<"  *  ";
            cout<<b[i]<<endl;
        }*/
        for(int i=0;i<n;i++) {
            LLU comp=a[i]*b[i];
            LLU aplus=(a[i]+1)*b[i]-comp;
            LLU aminus=(a[i]-1)*b[i]-comp;
            //LLU bplus=(b[i]+1)*a[i]-comp;
            //LLU bminus=(b[i]-1)*a[i]-comp;
            //cout<<aplus<<"\t"<<aminus<<"\t"<<bplus<<"\t"<<bminus<<endl;
            LLU maximum=max(aplus,aminus);
            //cout<<maximum<<"\t"<<overall_max<<endl;
            if(maximum>overall_max) {
                pos=i;
                overall_max=maximum;
            }
        }
    	//cout<<pos<<endl;
        LLU sum=0;
        for(int i=0;i<n;i++) {
            if(i==pos)
                continue;
            else
                sum+=(a[i]*b[i]);
        }
        LLU comp=a[pos]*b[pos];
        /*for(int i=0;i<k;i++) {
            LLU aplus=(a[pos]+1)*b[pos]-comp;
            LLU aminus=(a[pos]-1)*b[pos]-comp;
            //LLU bplus=(b[pos]+1)*a[pos]-comp;
            //LLU bminus=(b[pos]-1)*a[pos]-comp;
            //cout<<a[pos]<<"\t"<<b[pos]<<endl;
            if(aplus>=aminus) 
                ++a[pos];
            else if(aminus>=aplus)
                --a[pos];*/
            /*else if(bplus>=aminus && bplus>=bminus && bplus>=bminus)
                ++b[pos];
            else if(bminus>=aminus && bminus>=bplus && bminus>=aplus)
                --b[pos];*/
        //}
        /*if(k>abs(c-d)) {
        	if(c>d) {
        		k-=(c-d);
			}
			else {
				k-=(d-c);
			}
			c=d;
			if(k%2==0) {
				c+=(k/2);
				d+=(k/2);
			}
			else {
				c+=(k/2)+1;
				d+=(k/2);
			}
			sum+=(c*d);
		}
		else {
			if(c<d) 
				c+=k;
			else
				d+=k;
			sum+=(c*d);
		}*/
		//LLU comp=(a[pos]*b[pos]);
		if((((a[pos]+1)*b[pos])-comp) > (((a[pos]-1)*b[pos])-comp)) {
			a[pos]+=k;
		}
		else
			a[pos]-=k;
        cout<<sum+(a[pos]*b[pos])<<endl;
        
    }
	return 0;
}

