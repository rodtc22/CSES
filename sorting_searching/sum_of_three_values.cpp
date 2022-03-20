#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5 + 5;
 
int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	ii ar[n];
	for(int i= 0 ; i< n;i++) scanf("%d",&ar[i].first),ar[i].second = i+1;
	sort(ar,ar+n);
 
	bool sw = 0;
	for(int a = 0 ; a < n-2 ;a++){
		for(int b = a + 1 ; b < n-1 ;b++){
			int c = 0LL + x - ar[a].first - ar[b].first;
			int l = b + 1, r = n-1;
			while(l<=r){
				int m = (l+r)>>1;
				if(ar[m].first==c){
					printf("%d %d %d\n",ar[a].second,ar[b].second,ar[m].second);
					return 0;
				}
				else if(ar[m].first<c) l = ++m;
				else r = --m;
			}
 
		}
	}
	printf("IMPOSSIBLE\n");
	return 0;
}