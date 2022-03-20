#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int N = 200005;

//CON BUSQUEDA BINARIA SOBRE LA SUMA OBTENIDA, SI SE PUEDE DIVIDIR EN ESA
//CANTIDAD DE SEGMENTOS K, ENTONCES LA RESPUESTA ES VALIDA

int n,k;
int ar[N];

bool f(ll m){
	int cont = 0;
	ll acu =0;
	for(int i= 0 ; i < n;i++){
		if(ar[i]>m) return 0;
		acu += ar[i];
		if(acu==m){
			acu = 0;
			cont++;
		}else if(acu > m){
			acu = ar[i];
			cont++;
		}
	}
	if(acu) cont++;
	// cout<<m<<" "<<cont<<endl;
	return cont <= k;
}

int main(){
	scanf("%d %d",&n,&k);
	int maxi = -1;
	for(int i= 0  ;i < n;i++) scanf("%d",&ar[i]);

	ll r = 0,l = 0,m;
	for(int i= 0 ;i <n ;i++) r += ar[i],maxi = max(maxi,ar[i]);

	while(l<=r){
		m = (l+r)>>1;
		f(m)? r = --m : l = ++m;
	}
	printf("%lld\n",l);

	return 0;
}