#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;
 
int main(){
	int n; scanf("%d",&n);
	vector<ii>ar(n);
	for(auto &d:ar) scanf("%d %d",&d.first,&d.second);

	sort(ar.begin(),ar.end(),[] (ii a ,ii b) -> bool {
		if(a.second == b.second) return a.first<b.first;
		return a.second<b.second;
	});

	int ans = 0;
	int i= 0;
	int ini = 0, fin = 0;
	while(i<n){
		if(ar[i].first >= fin){
			ans++;
			tie(ini,fin) = {ar[i].first,ar[i].second};
		}
		i++;
	}
	printf("%d\n",ans);
	// for(auto d:ar) cout<<d.first<<" "<<d.second<<endl; cout<<endl;
	return 0;
}