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

vector<int> dist,ant,route;

void calcula_distancias(int node){
	queue<int>q;
	q.push(node);
	dist[node] = 0;

	while(q.size()){
		int u = q.front();q.pop();
		for(int v:graph[u]){
			if(dist[v]!=-1) continue;
			q.push(v);
			dist[v] =dist[u]+1;
			ant[v] = u;
		}
	}
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

	//solve
	dist.assign(n+1,-1);
	ant.assign(n+1,-1);
	calcula_distancias(1);

	route.clear();
	int destino = n;
	while(destino>0){
		route.push_back(destino);
		destino = ant[destino];
	}
	reverse(ALL(route));
	if(route.front()==1){
		cout<<route.size()<<endl;
		PRINT(route);
	}else{
		cout<<"IMPOSSIBLE\n";
	}
}