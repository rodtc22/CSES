#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e3+3;

//SIEMPRE HACER UNA DP ITERATIVA, NUNCA UNA RECURSIVA
//YA QUE HACER UNA RECURSIVA, ME GASTA MUUUCHO TIEMPO EN EL memset()

char grid[N][N];
int n;
vector<vector<int>> dp;

int main(){
	cin>>n;
	for(int i= 0 ;i< n ;i++)
		for(int j= 0 ;j< n;j++)
			cin>>grid[i][j];
	dp.resize(n+1,vector<int>(n+1,0));

	//dp
	dp[n-1][n-1] = (grid[n-1][n-1]!='*');

	for(int i= n-1 ;i>=0 ;i--){
		for(int j= n-1; j>=0 ;j--){
			if(i==n-1 && j== n-1) continue;
			int ac = (dp[i+1][j] + dp[i][j+1]) % M;
			dp[i][j] += ac;
			dp[i][j] %= M;

			if(grid[i][j]=='*') dp[i][j] = 0;
		}
	}
	printf("%d\n",dp[0][0]);
	// for(int i= 0 ;i< n; i++)
	// 	for(int j= 0 ;j<n ;j++)
	// 		cout<<dp[i][j]<<" \n"[j==n-1];
}