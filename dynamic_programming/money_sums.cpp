#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
#define PRINT(x) {for(auto d:x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e3+3;

/*ESTA ES LA CLASICA DP DONDE TIENES QUE MARCAR CON BOOLEANOS, PARA VER
SI SE PUEDE GENERAR O NO 
	
tambien sirve para practicar "cual es el ... tomando los primeros i-elementos"

pero en esta ocasion para optimizar memoria, solo vamos a usar un vector, 
en lugar de una matriz*/

vector<bool>dp;
vector<int> coin;
int n;

int main(){
	scanf("%d",&n);
	coin.resize(n);
	for(int &d:coin) scanf("%d",&d);

	//DP
	int tam = 100005;
	dp.resize(tam,false);
	dp[0] = true;

	for(int i= 0 ;i< n;i++){
		for(int j = tam-1 ;j>=0 ;j--)
			if(j + coin[i] < tam)
				dp[j+coin[i]] = dp[j+coin[i]] || dp[j]; // si se pudo generar en la j, entonces en la j+coin[j] tambien
			//tengo que ponerle or, porque es posible que sobre escriba un true con un false
	}
	
	int cont = 0;
	for(int i= 1 ;i< tam ;i++) 
		cont += dp[i];
	printf("%d\n",cont);
	for(int i= 1 ;i<tam ;i++) if(dp[i]) printf("%d ",i); printf("\n");
	return 0;
}