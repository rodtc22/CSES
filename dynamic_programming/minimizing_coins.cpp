#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e6+6;

int items[102];
int target[N];
int n,k;
int oo = 1e8+8;

int f(int x){
	if(x<0) return oo; //como hay que minimizar entonces devuelvo un valor grande
	if(x==0) return 0; // si se alcanzo el valor, entonces devuelvo un cero para que no afecte el contador

	int &ans = target[x];
	if(ans != -1) return ans;

	//tengo que recorrer todas las posibles monedas
	ans = oo;
	for(int i= 0 ;i<n ;i++)
		ans = min(ans,f(x-items[i])+1); // el monto que tengo en ese momento menos el monto i-esimo, significa que como estoy tomando una moneda extra, entonces la tengo que contar
	return ans;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i= 0 ;i< n ;i++) scanf("%d",&items[i]);
	memset(target,-1,sizeof target);
	int ans = f(k);
	if(ans == oo) ans = -1;
	printf("%d\n",ans);
	return 0;
}