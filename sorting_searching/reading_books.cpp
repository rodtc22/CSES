#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5 + 5;

int main(){
	int n;
	scanf("%d",&n);
	ll ar[n+1]={};
	for(int i= 1 ;i <= n;i++) scanf("%lld",&ar[i]);
	sort(ar,ar+n+1);
	
	ll last =ar[n];
	for(int i= 1; i<=n ;i++) ar[i] += ar[i-1];

	ll ans = ar[n];
	if(last >= ar[n-1])
		ans += (last-ar[n-1]); 

	printf("%lld\n",ans);
	return 0;
}
