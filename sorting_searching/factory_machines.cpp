#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5 + 5;
//BINARY SEARCH SOBRE EL TIEMPO

/*cuidado con poner 1e18, por que hay overflow
entonces hay que analizar cual es el valor maximo 
que puede tomar r, haciendo uso de binary search*/

ll ar[N],t;
int n;

ll many(ll time){
	ll cnt = 0;
	for(int i= 0 ;i< n ;i++)
		cnt += (time/ar[i]);
	return cnt;
}

int main(){
	scanf("%d %lld",&n,&t);
	for(int i= 0 ;i< n ;i++) scanf("%lld ",&ar[i]);

	int x = *min_element(ar,ar+n);
	ll l = 0, r = 1LL*x*t,m; 
	while(l<=r){
		m = (l+r)/2;
		if(many(m)>=t) r = m-1;
		else l = m+1; 
	}
	printf("%lld\n",l);
	return 0;
}