#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;

int main(){
	int n;
	scanf("%d",&n);
	int ant,x;
	ll ans = 0;
	scanf("%d",&ant);
	while(--n){
		scanf("%d",&x);
		if(x<ant){
			ans += (ant-x);
			x = ant;
		}
		ant = x;
	}
	printf("%lld\n",ans);
}