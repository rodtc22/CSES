#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;
 
int main(){
	int n,x,a;
	scanf("%d %d",&n,&x);
	vector<ii>ar(n);
	for(int i= 1; i<=n ;i++){
		scanf("%d",&a);
		tie(ar[i-1].first,ar[i-1].second)  = {a,i};
	}

	// for(auto d:ar) cout<<d.first<<" "<<d.second<<endl;
	sort(ALL(ar));

	for(int i= 0;i< n-1;i++){
		int pos = lower_bound(ar.begin()+i+1,ar.end(),ii(x-ar[i].first,-1)) - ar.begin();
		// if(pos == n) continue;
		if(ar[i].first + ar[pos].first == x){
			printf("%d %d\n",ar[i].second,ar[pos].second);
			return 0;
		}
	}
	printf("IMPOSSIBLE\n");
	return 0;
}