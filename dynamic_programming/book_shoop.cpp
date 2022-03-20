#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
#define PRINT(x) {for(auto d:x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e3+3;

//SIEMPRE HACER UNA DP ITERATIVA, NUNCA UNA RECURSIVA
//YA QUE HACER UNA RECURSIVA, ME GASTA MUUUCHO TIEMPO EN EL memset()


vector<vector<int>> dp;
vector<int> cost,pages;
int n,k;

int main(){
	scanf("%d %d",&n,&k);
	cost.resize(n),pages.resize(n);
	dp.assign(n+1,vector<int>(k+1,0));
	for(int &d:cost) scanf("%d",&d);
	for(int &d:pages) scanf("%d",&d);

	//DP
	// esta  es la forma de cuando es lo tomas  o NO lo tomas	
	for(int i= 1; i<=n ;i++){
		//cuando no lo tomas, solo copias
		for(int j= 0  ;j <= k ; j++) dp[i][j]  = dp[i-1][j];
		//cuando lo tomas, debes recorrer de derecha a izquierda para no estar validando cosas
		for(int j = k; j >= 0 ;j--)
			if(j+cost[i-1]<=k)
				dp[i][j+cost[i-1]] = max(dp[i][j+cost[i-1]],dp[i][j]+pages[i-1]);
	}
	printf("%d\n",dp[n][k]);

	// for(int i= 0 ;i<=n;i++) for(int j= 0 ;j<= k ;j++) cout<<dp[i][j]<<" \n"[j==k];
	return 0;
}