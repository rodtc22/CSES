#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
#define PRINT(x) {for(auto d:x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e3+3;
const int oo = 1e9;

int main(){
	string a,b;
	int n,m;
	cin>>a>>b;
	n = a.size() , m = b.size();
	a = '$'+a; b = '$'+b;

	vector<vector<int>> dp(n+1,vector<int>(m+1,oo));
	//casos base
	for(int i= 0 ;i<=n ;i++) dp[i][0] = i;
	for(int j= 0 ;j<=m ;j++) dp[0][j] = j;

	//dp
	for(int i= 1; i<=n ;i++){
		for(int j= 1 ;j<=m ;j++){
			//hacer el cambio de letra involucra costo 1 y comparar lo anterior
			dp[i][j]  = min(dp[i][j],1+dp[i-1][j-1]);

			//quitar involucra costo 1 y que hay que comparar i-1 == k
			dp[i][j] = min(dp[i][j],1+dp[i-1][j]);

			//aumentar involucra costo 1 y que i+1 == k, entonces comparamos i == k-1
			dp[i][j] = min(dp[i][j],1+dp[i][j-1]);

			//si son iguales involucra solo comparar i-1 == k-1
			if(a[i]==b[j])
				dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
		}
	}
	printf("%d\n",dp[n][m]);
	// for(int i = 0 ;i<=n; 	i++) for(int j= 0 ;j<=m ;j++) cout<<dp[i][j]<<" \n"[j==m];
	return 0;
}