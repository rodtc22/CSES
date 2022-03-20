#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int y,x;
		scanf("%d %d",&y,&x);
		int maxi = max(y,x);
		ll nro =  1LL*maxi*maxi -  maxi + 1;
		if(y!=x){
			if(x==maxi){
				if(x&1) nro += (maxi-y);
				else nro += (y-maxi);
			}else{
				if(y&1) nro += (x-maxi);
				else nro += (maxi - x);
			}
		}
		printf("%lld\n",nro);

	}
	return 0;
}