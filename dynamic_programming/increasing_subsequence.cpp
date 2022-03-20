#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
#define PRINT(x) {for(auto d:x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e3+3;
const int oo = 1e9;

//dp[x] = valor maximo mas pequenio para una LIS de tamanio x
//aqui nos preocupamos de que si tenemos una LIS de tamanio x, elegimos el que 
//nos de mejores oportunidades, es decir , es mejor 1 2 3 4  que 1 2 3 6

int main(){
	int n;
	scanf("%d",&n);
	vector<int>ar(n);
	for(int &d:ar) scanf("%d",&d);

	vector<int>dp(n+2,oo);
	dp[0] = -1;
	dp[1] = ar[0];
	for(int i= 1 ;i<n ;i++){
		int pos = upper_bound(begin(dp),end(dp),ar[i])-begin(dp);
		// cout<<pos<<endl;
		if(dp[pos-1] != ar[i])
			dp[pos] = min(dp[pos],ar[i]);
	}
	
	//para hallar la respuesta hallamos la posicion mas grande que no sea infinito
	// equivalente a la posicion anterior del primer oo
	int ans = lower_bound(dp.begin(),dp.end(),oo)-dp.begin();
	printf("%d\n",ans-1);

	// PRINT(dp);   //para entender mejor como es que funciona
	return 0;
}