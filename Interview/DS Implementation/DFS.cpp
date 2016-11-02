#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<utility>
#include<stack>
#include<bitset>
using namespace std;

void bfs(vector<list<pair<int,int> > > &graph, int v) {
	cout<<endl<<endl;
	//int visit[v+1];
	bitset<100> visit;
	stack<int> search;
	search.push(1);
	while(!search.empty()) {
		int vtx = search.top();
		search.pop();
		if(visit.test(v-vtx+1)) {
			continue;
		}
		else {
			visit.set(v-vtx+1,1);
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
		cin>>s>>d;
		w=0;
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
