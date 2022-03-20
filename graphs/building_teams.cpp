#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int oo =  1e9;
const int N = 2e5 + 5;

int n,m;
vector<vector<int>>graph;

//cuando te dice que van ser dos grupos, entonces pensamos en un grafo bipartito
bool ok;
vector<int> team;

void bipartite(int u , int t){
	
	if(team[u]>0 && team[u]!=t) {
		ok = false; 
		return;
	}
	if(team[u]>0) return;

	team[u] = t;
	for(int v:graph[u])
		bipartite(v,3-t);
}

int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	graph.assign(n+1,vector<int>());
	while(m--){
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	ok = true; // por el momento pensamos que si se puede
	team.assign(n+1,0);

	for(int i= 1;i<=n ;i++){
		if(team[i]>0) continue;
		bipartite(i,1);
	}
	if(ok){
		for(int i= 1; i<=n ;i++) printf("%d ",team[i]); printf("\n");
	}else{
		printf("IMPOSSIBLE\n");
	}
	return 0;
}