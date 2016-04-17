#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define length 100000000
using namespace std;

long long unsigned arr[100000005];
int main() {
    
    arr[1]=3;
    for(int i=2;i<=length;i++) {
        arr[i]=3+(i-1)*2+(arr[i-1]-i);
    }
    int t;
    cin>>t;
    while(t--) {
        long long unsigned n;
        cin>>n;
        if(n<=length)
            cout<<arr[n]<<endl;
        else {
            long long unsigned ans=arr[length];
            for(long long unsigned j=length+1;j<=n;j++) {
                ans=3+(j-1)*2+(ans-j);
            }
            cout<<ans<<endl;
        }
    }        
    return 0;
}

