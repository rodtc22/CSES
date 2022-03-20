#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1003;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	ll ar[n+1]={};
	for(int i= 1  ;i<=n ;i++) scanf("%lld",&ar[i]);
	for(int i= 1 ;i<=n ;i++) ar[i] += ar[i-1];

	map<ll,int> rep;
	rep[0]++;
	ll cont = 0;
	for(int i = 1; i <=n ;i++){
		cont += rep[ar[i]-m];
		rep[ar[i]]++;
	}
	printf("%lld\n",cont);
	return 0;
}