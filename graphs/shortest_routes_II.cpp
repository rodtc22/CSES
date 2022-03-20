#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;
const int N = 2e5 + 5;
const int M = 1e9+7;
 
int n,m;
vector<vector<ll>> graph,dist;
int main(){
	int q;
	scanf("%d %d %d",&n,&m,&q);
	graph.assign(n+1,vector<ll>(n+1,0));
	dist.assign(n+1,vector<ll>(n+1,oo));
	while(m--){
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		if(graph[u][v]==0) graph[u][v] = c;
		else graph[u][v] = min(graph[u][v],0LL+c);
		graph[v][u] = graph[u][v];
	}

	for(int i= 1; i<=n ;i++){
		for(int j= 1 ;j<=n ;j++){
			if(i==j) dist[i][j] = 0;
			else if(graph[i][j]) dist[i][j] = graph[i][j];
			else dist[i][j] = oo;
		}
	}

	//floyd
	for(int k= 1 ;k <=n ;k++)
		for(int i= 1; i<=n ;i++)
			for(int j= 1; j<=n ; j++)
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

	while(q--){
		int u,v;
		scanf("%d %d",&u,&v);
		if(dist[u][v]==oo) dist[u][v]=-1;
		printf("%lld\n",dist[u][v]);
	}
}