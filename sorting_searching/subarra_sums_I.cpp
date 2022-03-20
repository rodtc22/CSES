#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1003;

//NUEVAMENTE NECESITAREMOS HACER VECTOR DE ACUMULADAS PARA HACER LOS CALCULOS MAS RAPIDO
//Y RECORDAR QUE LA SUMA DE VALORES POSITIVOS TIENE LA PROPIEDAD DE QUE
//ESA SUMA ES UNA FUNCION MONOTONA

int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	ll ar[n+1]={};
	for(int i= 1 ;i<=n ;i++) scanf("%lld",&ar[i]);
	for(int i= 1 ;i<=n ;i++) ar[i] += ar[i-1];

	int a = 0,b = 1;
	int cont = 0;
	for(; b <= n ; b++){
		while(ar[b]-ar[a] > x) a++;
		cont += (x == ar[b]-ar[a]);
	}
	printf("%d\n",cont);
	return 0;
}