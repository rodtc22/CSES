#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1003;

int main(){
	int n; scanf("%d",&n);
	map<int,ll> oc;
	oc[0] = 1;
	ll ac = 0;
	for(int i= 0 ;i < n;i++){
		int x; scanf("%d",&x);
		ac = (0LL + ac + (x%n) + n) % n;
		oc[ac]++;
	}

	ll ans = 0;
	for(auto d:oc)
		ans += ((1LL*d.second*(d.second-1))>>1);

	printf("%lld\n",ans);
	return 0;
}