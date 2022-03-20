#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e6+1;

//SIEMPRE HACER UNA DP ITERATIVA, NUNCA UNA RECURSIVA
//YA QUE HACER UNA RECURSIVA, ME GASTA MUUUCHO TIEMPO EN EL memset()

vector <int> dp;
//dp[x] cantidad de formas para lograr x

int main(){
	int x; scanf("%d",&x);
	dp.assign(x+1,0); // inicia en 0, por que es el caso neutro cuando x<0

	dp[0]=1;  //hay una forma para sumar cero, y es , no sumar nada
	dp[1]=1;  //cantidad de formas de formar 1

	for(int i = 2; i <= x ;i++){
		for(int j = 1; j<=6 ;j++){
			if(i-j>=0){	//para evitar el caso neutro,ademas valida que no se salga del array
				dp[i] = dp[i] + dp[i-j];
				dp[i] %= M;
			}
		}
	}
	printf("%d\n",dp[x]);
	return 0;
}