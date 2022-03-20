#include <bits/stdc++.h>
using namespace std;

#define ALL(x)  x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;

int main(){
	int n; scanf("%d",&n);
	vector<ii> ar(n<<1);
	for(int i= 0  ;i< (n<<1); i++){
		scanf("%d",&ar[i].first);
		ar[i].second = (i&1)? -1 : 1;
	}
	sort(ar.begin(),ar.end());

	int ac =0;
	int ans = 0;
	for(ii a:ar){
		ac+=a.second;
		ans = max(ans,ac);
	}
	printf("%d\n",ans);
	return 0;
}