#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<utility>
#include<queue>
//#include<bitset>
using namespace std;

void bfs(vector<list<pair<int,int> > > &graph, int v) {
	cout<<endl<<endl;
	int visit[v+1];
	queue<int> search;
	search.push(1);
	while(!search.empty()) {
		int vtx = search.front();
		search.pop();
		if(visit[vtx] == 1) {
			continue;
		}
		else {
			visit[vtx]=1;
			cout<<vtx<<"->";
			for(list<pair<int,int> >::iterator it = graph[vtx].begin(); it != graph[vtx].end(); it++) {
				search.push((*it).first);
			}
		}
		
	}
}

int main(void) {
	int v,e;
	cin>>v>>e;
	vector<list<pair<int,int> > > graph(v+1);
	while(e > 0) {
		e--;
		int s,d,w;
		w=0;
		cin>>s>>d;
		graph[s].push_back(make_pair(d,w));
		graph[d].push_back(make_pair(s,w));
	}
	for(int i=1; i<=v; i++) {
		list<pair<int,int> >::iterator it = graph[i].begin();
		cout<<i<<"->";
		while( it != graph[i].end()) {
			cout<<(*it).first<<"->";
			it++;
		}
		cout<<"\b \b\b \b"<<endl;
	}
	bfs(graph,v);
}
