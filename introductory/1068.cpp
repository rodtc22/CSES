#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;

int main(){
	ll n;
	scanf("%lld",&n);
	while(n!=1){
		printf("%lld ",n);
		n = (n&1)? (n*3 + 1): n>>1;
	}
	printf("1\n");
	return 0;
}