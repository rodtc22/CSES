#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;
const int N = 2e5 + 5;
const int M = 1e9+7;

int n;
vector<vector<int>> tree;
vector<int> subtree;

void dfs(int u, int ant){
	subtree[u] = 1;
	for(auto v:tree[u]){
		if(ant == v) continue;
		dfs(v,u);
		subtree[u] += subtree[v]; 
	}
}

int main(){
	scanf("%d",&n);
	tree.assign(n+1,vector<int>());
	subtree.assign(n+1,0);

	for(int i= 2; i <=n ;i++){
		int x; scanf("%d",&x);
		tree[x].push_back(i);
		tree[i].push_back(x);
	}

	dfs(1,0);

	for(int i = 1; i <= n ;i++) printf("%d ",subtree[i]-1);printf("\n");

	return 0;
}