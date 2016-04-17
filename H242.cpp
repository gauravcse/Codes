#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
	cin>>t;
	while(t--){
		int v,e;
		cin>>v>>e;
		int degree[v+1];
		for(int i=0;i<=v;i++)
			degree[i]=0;
		for(int i=0;i<e;i++) {
			int u,k;
			cin>>u>>k;
			degree[u]++;
			degree[k]++;
			
		}
		int ans=0;
		for(int i=1;i<=v;i++) {
			if(degree[i]==0)
				ans+=1;
			else
				ans+=degree[i];
		}
		cout<<ans+1<<endl;
	}
    return 0;
}

