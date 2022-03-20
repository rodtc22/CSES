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
	ll ac[n+1]={};
	for(int i= 1; i<=n ;i++) scanf("%lld",&ac[i]);
	for(int i= 1 ;i<=n ;i++)
		ac[i] += ac[i-1];
	ll ans = -1e18;
	ll mini = ac[0];
	for(int i= 1; i<=n ;i++){
		ans = max(ans,ac[i]-mini);
		mini = min(mini,ac[i]);
	}
	printf("%lld\n",ans);
	return 0;
}