#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e6+1;

//SIEMPRE HACER UNA DP ITERATIVA, NUNCA UNA RECURSIVA
//YA QUE HACER UNA RECURSIVA, ME GASTA MUUUCHO TIEMPO EN EL memset()

vector<int>dp,coin;
int n,k;

int main(){
	scanf("%d %d",&n,&k);
	coin.resize(n);
	dp.resize(k+1,0); //lo rellenamos con el neutro
	for(int &d:coin) scanf("%d",&d);

	//dp
	dp[0] = 1;
	// a diferencia del anterior, priorizo "con la moneda i-esima cuales puedo gneerar", por eso no hay repetidos como el anterior
		for(int j= 0 ; j<n ; j++){ 
	for(int i = 1 ; i <= k ;i++){
			if(i-coin[j]>=0){
				dp[i] += dp[i-coin[j]];
				dp[i] %= M;
			}
		}
	}
	printf("%d",dp[k]);
	return 0;
}