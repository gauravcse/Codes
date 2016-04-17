#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

int adj[1005][1005];
int dist[1005];
queue<int> bfsq;

void bfs(int s,int v) {
    if(bfsq.empty())
        return;
    else {
        int row=bfsq.front();
        //cout<<row<<endl;
        bfsq.pop();
        for(int i=1;i<=v;i++) {
            if(adj[row][i]!=0 && i!=row && dist[i]==-1) {
          //      cout<<row<<"  "<<i<<endl;
                dist[i]=dist[row]+6;
                bfsq.push(i);
            }
        }
        if(!bfsq.empty())
            bfs(bfsq.front(),v);
        else
            return;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int v,e;
        cin>>v>>e;
        for(int i=1;i<=v;i++) {
            dist[i]=-1;
            for(int j=1;j<=v;j++) {
                if(i==j)
                    adj[i][j]=1;
               else
                    adj[i][j]=0;
            }
        }
        for(int i=0;i<e;i++) {
            int u,w;
            cin>>u>>w;
            adj[u][w]=1;
        }
        int source;
        cin>>source;
        bfsq.push(source);
        dist[source]=0;
        bfs(source,v);
        for(int i=1;i<=v;i++) {
            if(i!=source) {
                if(dist[i]==0)
                    cout<<"-1 ";
                else
                    cout<<dist[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

