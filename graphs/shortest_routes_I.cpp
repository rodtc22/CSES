#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;
const int N = 2e5 + 5;
const int M = 1e9+7;
 
typedef pair<ll,int> nodo; // costo,node_origin
 
//BASICAMENTE ES SOLO HACER DIJKSTRA
 
int n,m;
vector<vector<ii>> graph; //valor, costo
vector<ll> dist;
 
void dijkstra(int node){
	priority_queue<nodo,vector<nodo>, greater<nodo>> pq;
	dist.assign(n+1,oo);
	ll dist_u = 0;
	int u = node;
	
	pq.push({dist_u,u});
 
	while(pq.size()){
		dist_u = pq.top().first;
		u = pq.top().second;
		pq.pop();
 
		if(dist_u>dist[u]) continue;
		dist[u] = dist_u; 
 
		for(auto x: graph[u]){
			int v = x.first;
			ll dist_v = x.second;
 
			if(dist[v] > 0LL+dist_u + dist_v){
				pq.push({dist_u+dist_v,v});
			}
		}
	}
}
 
int main(){
	int u,v;
	ll c;
	scanf("%d %d",&n,&m);
	graph.assign(n+1,vector<ii>());
	while(m--){
		scanf("%d %d %lld",&u,&v,&c);
		graph[u].push_back({v,c});
	}
 
	dijkstra(1);
	for(int i= 1 ;i<=n ;i++) printf("%lld ",dist[i]); printf("\n");
	return 0;
}