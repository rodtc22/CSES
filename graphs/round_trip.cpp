#include <bits/stdc++.h>
using namespace std;

#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;
const int N = 2e5 + 5;
const int M = 1e9+7;

vector<vector<int>> graph;
vector<int> ans,stat;

bool sw;

//stat -1 : no ha sido visitado todavia
//stat 0  : esta en la pila de recursion
//stat 1  : ya fue visitado y no tiene ciclo desde ese nodo

void dfs(int u,int ant){
    ans.push_back(u); 
    if(stat[u]==0){
        sw = 1;
        return ;
    }
    stat[u]++;
    for(auto v:graph[u]){
        if(v == ant) continue;
        dfs(v,u);
        if(sw) return;
    }
    ans.pop_back(); stat[u]++;
}


int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    graph.assign(n+1,vector<int>());
    while(m--){
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    stat.assign(n+1,-1);
    for(int i= 1 ;i<= n; i++){
        if(stat[i]!=-1) continue;
        ans.clear(); sw = false;
        dfs(i,-1);
        if(sw){
            sw = 0;
            stat.clear();
            for(auto x:ans){
                sw |= (x == ans.back());
                if(sw) stat.push_back(x);
            }
            printf("%ld\n",stat.size());
            PRINT(stat);
            return 0;
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}