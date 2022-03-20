#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;

/*cuando puedas, hazte los casos de prueba 
para verificar que corra bien, es mejor
prevenir que lamentar*/

int main(){
	int t;
	ll k;
	scanf("%d",&t);
	ll ac[20]={};

	ll nro = 1;
	for(int i= 1; ;i++){
		ac[i]=ac[i-1]+(1LL*i*(nro*9));
		nro *= 10;
		if(ac[i]> 1e18) break;
	}
	while(t--){
		scanf("%lld",&k);
		int pos = 1;
		for(; ac[pos]<k;pos++){}
		ll ans = pow(10,pos-1);
		k-=ac[pos-1];
		k--;
		ans+=(k/pos);
		// cout<<ans<<endl;
		k%=pos;
		string s= to_string(ans);
		printf("%c\n",s[k]);
	}
	return 0;
}