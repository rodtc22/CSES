#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;

int main(){
	int n;
	scanf("%d",&n);
	int ar[n];
	for(int i= 0  ;i< n;i++) scanf("%d",&ar[i]);

	ll ans = 1e18;
	for(int i = 0 ; i < (1<<n) ; i++){
		ll a = 0,b  = 0;
		for(int j= 0 ;j < n; j++){
			if(i&(1<<j)) a+=ar[j];
			else b+=ar[j];
		}
		ans = min(ans,ll(labs(a-b)));
	}
	printf("%lld\n",ans);
	return 0;
}