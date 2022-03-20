#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e6+1;

//SIEMPRE HACER UNA DP ITERATIVA, NUNCA UNA RECURSIVA
//YA QUE HACER UNA RECURSIVA, ME GASTA MUUUCHO TIEMPO EN EL memset()

vector <int> dp,coin;
int n,k,oo = 1e9;

int main(){
	scanf("%d %d",&n,&k);
	coin.resize(n);
	dp.resize(k+1,oo);
	for(int &d:coin) scanf("%d",&d);

	//dp
	dp[0] = 0; //caso base,donde la cantidad minima de monedas para sumar cero, es no poner ninguna moneda
	for(int i = 1; i<=k ;i++){
		//lo tendria que poner con el neutro, pero como lo construi con el neutro
		//entonces no tengo nada de que preocuparme
		for(int j= 0 ;j < n; j++)
			if(i - coin[j] >= 0)
				dp[i] = min(dp[i],dp[i-coin[j]]+1);
	}
	for(auto a:dp) cout<<a<<" ";cout<<endl;
	return 0;
}