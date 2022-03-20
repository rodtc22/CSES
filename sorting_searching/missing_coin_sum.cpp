#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef long long ll;

int main(){
	int n;
	scanf("%d",&n);
	int ar[n];
	for(int i= 0 ;i < n ;i++) scanf("%d",&ar[i]);
	sort(ar,ar+n);
	ll ans = 0;
	for(int i= 0 ;i < n;i++){
		if(ans +1 < ar[i])
			break;
		ans += ar[i];
	}
	printf("%lld\n",ans+1);
	return 0;
}