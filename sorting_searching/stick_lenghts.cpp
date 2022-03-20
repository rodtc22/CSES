#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;
 

// MEDIANA es la minima distancia de todos los puntos, a un punto
int main(){
	int n;
	scanf("%d",&n);
	int ar[n];
	for(int i= 0 ;i<n; i++) scanf("%d",&ar[i]);
	sort(ar,ar+n);
	ll ans = 0;
	
	for(int i= 0 ;i< n;i++)
		ans += labs(ar[n>>1]-ar[i]);
	
	// si es par, entonces hay dos candidatos a mediana
	if(!(n&1)){
		ll ans2 = 0;
		for(int i= 0 ;i< n;i++)
			ans2 += labs(ar[(n-1)>>1]-ar[i]);

		ans = min(ans,ans2);
	}
	printf("%lld\n",ans);
	return 0;
}