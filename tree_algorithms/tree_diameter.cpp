#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e8;
const int N = 2e5 + 5;
const int M = 1e9+7;

//calcular el diametro del un arbol

int n;
vector<vector<int>> tree;

vector<int>dist;
void dfs(int u, int ant){
	for(auto v: tree[u]){
		if(v == ant) continue;
		dist[v] = dist[u] + 1;
		dfs(v,u);
	}
}

int lejano(int node){
	dist.assign(n+1,oo);
	dist[node] = 0;
	dfs(node,-1);

	//ahora que las distancias ya han sido calculadas, retornamos el indice del nodo
	return max_element(dist.begin()+1,dist.begin()+1+n) - dist.begin();
}

int main(){
	int u,v;
	scanf("%d",&n);
	tree.assign(n+1,vector<int>());

	for(int i= 0 ;i< n-1 ;i++){
		scanf("%d %d",&u,&v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	//buscamos el un nodo hoja lejano
	int leaf = lejano(1);

	//ahora hallamos quien esta mas lejos desde este nodo hoja
	int pos = lejano(leaf);
	int ans = dist[pos];

	printf("%d\n",ans);
	return 0;
}


/*el mejor caso de prueba
        *
        |  
* - * - * - * - **/