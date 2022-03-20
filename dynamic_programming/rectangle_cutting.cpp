#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int oo =  1e9;
const int N = 2e5 + 5;
 
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int n = 500;

	vector<vector<int>> dp(n+1,vector<int>(n+1,0));

	//DP
	for(int i= 1 ;i<=n ;i++){
		for(int j= i ;j <=n ;j++){
			if(i==j) dp[i][j] = 0;
			else dp[i][j] = oo;

			for(int k = 1 ; k < i ; k++) dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]);
			for(int k = 1 ; k < j ; k++) dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]);
			
			if(i!=j) dp[i][j]++;
			dp[j][i] = dp[i][j];
		}
	}

	printf("%d\n",dp[a][b]);
	// for(int i= 1 ; i<=n ;i++) for(int j= 1; j<=n ;j++) cout<<dp[i][j]<<" \n"[j==n];
	return 0;
}