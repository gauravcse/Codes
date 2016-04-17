#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int min=100;
    for(int i=0;i<n;i++) {
        if(arr[i]<min)
            min=arr[i];
    }
    cout<<min<<"Min\n";
    if(min>m) {
        cout<<"0";
    }
    else{
        int dp[m+1];
        for(int i=0;i<=m;i++)
            dp[i]=0;
        dp[min]=1;
        for(int i=min+1;i<=m;i++) {
            int max=0;
            for(int j=min;j<i;j++) {
                int temp=0;
                for(int k=0;k<n;k++) {
                    if((j+arr[k])==i) {
                        temp=dp[j];
                        break;
                    }
                }
                max+=temp;
            }
            dp[i]=max;
        }
        for(int i=0;i<=m;i++)
            cout<<dp[i]<<"\t";
    }
}

