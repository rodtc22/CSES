#include <bits/stdc++.h>
using namespace std;

#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;
const int N = 2e5 + 5;
const int M = 1e9+7;

int n;
vector<int> bag;
ll dp [5000][5000][2];

ll f(int a, int b, bool take_it){

	if(a==b) return take_it * bag[a];

	ll &r = dp[a][b][take_it];
	if(r!=-1) return r;

	ll xa = take_it * bag[a] + f(a+1,b,!take_it);
	ll xb = take_it * bag[b] + f(a,b-1,!take_it);
	
	if(take_it) r = max(xa,xb);
	else r = min(xa,xb);
	return r;
}

int main(){
    scanf("%d",&n);
    bag.resize(n);
    for(int&d:bag) scanf("%d",&d);
    memset(dp,-1,sizeof dp);

	ll ans = f(0,n-1,1);
	printf("%lld\n",ans);
    return 0;
}