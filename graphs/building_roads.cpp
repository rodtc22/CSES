#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int oo =  1e9;
const int N = 2e5 + 5;

int n,m,nro_group = 0;
vector<vector<int>>graph;
vector<int> group;
vector<ii> edges;

void agrupar(int u){
	group[u] = nro_group;
	for(int v:graph[u]){
		if(group[v]!=-1) continue;
		agrupar(v);
	}
}

int main(){
	scanf("%d %d",&n,&m);
	graph.assign(n+1,vector<int>());
	group.assign(n+1,-1);

	while(m--){
		int u,v;
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int ant = -1;
	for(int i= 1; i<=n ;i++){
		if(group[i]!=-1) continue;
		nro_group++;
		agrupar(i);
		if(ant!=-1){
			edges.push_back({ant,i});
		}
		ant = i;
	}
	cout<<edges.size()<<endl;
	for(auto x:edges)	cout<<x.first<<" "<<x.second<<endl;
	 
	return 0;
}