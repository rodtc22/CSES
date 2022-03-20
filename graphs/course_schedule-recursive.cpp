#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;
const int N = 2e5 + 5;
const int M = 1e9+7;

//SOLO HACER TOPOLOGICAL SORT RECURSIVO
//en esta implementacion tenemos que hacer otro dfs
//para deteccion de ciclos

int n,m;
vector<vector<int>>graph;
vector<bool> visited;
vector<int> topo;
vector<int> in_stack;

//detecting cicle in a directed graph

bool is_cicle(int u){
	if(in_stack[u]==0) return true;
	if(in_stack[u]==1) return false;

	bool sw = 0;
	in_stack[u]++;

	for(auto v: graph[u])
		sw |= is_cicle(v);

	in_stack[u]++;
	return sw;
}

void dfs(int u){
	visited[u] = true;
	for(auto v: graph[u])
		if(!visited[v])
			dfs(v);
	topo.push_back(u);
}

void init_topo(){
	topo.clear();
	for(int i= 1; i <= n; i++)
		if(!visited[i])
			dfs(i);
	reverse(ALL(topo));
}

int main(){
	scanf("%d %d",&n,&m);
	graph.assign(n+1,vector<int>());

	//LLENANDO EL GRAFO
	while(m--){
		int u,v;
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
	}
	
	/*-1 == no visited
	0  == in stack
	1  == out stack */
	in_stack.assign(n+1,-1);

	bool sw = 0;
	for(int i= 1 ;i<=n ;i++){
		if(in_stack[i]!=-1) continue;
		sw |= is_cicle(i);
		if(sw) break;
	}

	if(sw){
		printf("IMPOSSIBLE\n");
	}else{
		visited.assign(n+1,0);
		init_topo();
		PRINT(topo);
	}
	
	return 0;
}