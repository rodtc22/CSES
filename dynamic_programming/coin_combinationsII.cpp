#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e6+1;

//SIEMPRE HACER UNA DP ITERATIVA, NUNCA UNA RECURSIVA
//YA QUE HACER UNA RECURSIVA, ME GASTA MUUUCHO TIEMPO EN EL memset()

//neutro == algun estado al que no tengo que llegar, en recursion y tiene que salirse de alli
//caso base == caso valido que tambien se sale rapido y ayuda a la respuesta
//caso iteracion == recorrer el espacio de busqueda

vector<int>coin;
vector<vector<int>> dp; // {formar x, con las primeras i monedas}
int n,k;

int main(){
	scanf("%d %d",&n,&k);
	coin.resize(n+1);
	dp.assign(n+1,vector<int>(k+1,0));
	for(int i= 1; i<=n ;i++) scanf("%d",&coin[i]);

	//dp
	//caso base  x==0  -> 1
	dp[0][0] = 1;
	for(int i = 1 ;i <=  n;i++){
		for(int j = 0 ;j <= k; j++){
			dp[i][j] = dp[i-1][j];
			if(j - coin[i] < 0) continue;
			dp[i][j] += dp[i][j-coin[i]];
			dp[i][j] %= M; 
		}
	}
	printf("%d\n",dp[n][k]);
	
	return 0;
}