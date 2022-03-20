#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;
const int N = 2e5 + 5;
const int M = 1e9+7;

//SOLO HACER TOPOLOGICAL SORT
int n,m;
vector<vector<int>>graph;

//indegree= cantidad de nodos que procesar antes que yo
vector<int> indegree;

int main(){
	scanf("%d %d",&n,&m);
	graph.assign(n+1,vector<int>());
	indegree.resize(n+1,0);

	//LLENANDO EL GRAFO
	while(m--){
		int u,v;
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		indegree[v]++; //tengo un nodo más que procesar
	}

	//VERIFICANDO LOS QUE TIENEN IN_DEGREE==CERO
	queue<int> q;
	for(int i= 1 ;i<=n ;i++)
		if(indegree[i]==0)
			q.push(i);

	//AHORA SI HAGO EL PROCEDIMIENTO O(edges)

	int visited[n+1]={};
	vector<int> ans;

	for(int i= 1; i<=n ;i++){
		if(visited[i]) continue;
		
		while(q.size()){
			int u = q.front();
			q.pop();

			visited[u] = true;
			ans.push_back(u);

			for(auto v: graph[u]){
				indegree[v]--;
				if(indegree[v]==0)
					q.push(v);
			}
		}
	}
	if(ans.size()!=n) printf("IMPOSSIBLE\n");
	else PRINT(ans);
	return 0;
}