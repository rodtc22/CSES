#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
#define PRINT(x) {for(auto d:x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e3+3;
const int oo = 1e9;

// es la clasica dp de la mochila iterativa

int main(){
	int n;
	scanf("%d",&n);
	int total = n*(n+1)>>1;
	if(total & 1){
		printf("0\n");
	}else{
		total>>=1;

		vector<int>dp(total+1,0);
		dp[0] = 1;
		for(int i= 1 ; i<= n-1 ;i++){
			for(int k = total-i ; k >= 0 ;k--){
				dp[i+k] += dp[k];
				dp[i+k] %= M;
			}
		}
		printf("%d\n",dp[total]);
	}

	return 0;
}