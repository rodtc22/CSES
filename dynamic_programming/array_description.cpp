#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int oo =  1e9;
const int N = 2e5 + 5;
 
//IDEA CLAVE, SI TENGO X, PUEDO FORMAR X-1 , X, X+1

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int>ar(n);
	for(int &a:ar) scanf("%d",&a);

	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	
	for(int i= 0 ; i <= m; i++) 
		dp[0][i] = 1;
	// if(ar[0]==0){
	// }else{
	// 	dp[0][ar[0]]=1;
	// }

	for(int i= 0 ;i< n ;i++){
		if(ar[i]==0){
			for(int j= 1 ;j <= m; j++){
				for(int k = -1 ; k<= 1 ;k++){
					if(j+k>=1 and j+k <=m){
						dp[i+1][j+k] += dp[i][j];
						dp[i+1][j+k] %= M;
					}
				}
			}
		}else{
			int j =ar[i];
			for(int k = -1 ; k<= 1 ;k++){
				if(j+k>=1 and j+k <=m){
					dp[i+1][j+k] += dp[i][j];
					dp[i+1][j+k] %= M;
				}
			}
		}
	}
	
	// for(int i= 0 ;i<=n ;i++) for(int j = 0 ;j<=m ;j++) cout<<dp[i][j]<<" \n"[j==m];
	
	int ans = 0;
	if(ar[n-1]==0){
		for(int i= 1 ;i<=m;i++){
			ans += dp[n-1][i];
			ans %= M;
		}
	}else{
		ans = dp[n-1][ar[n-1]];
	}
	printf("%d\n",ans);
	return 0;
}