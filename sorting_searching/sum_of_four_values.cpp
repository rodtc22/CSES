#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1003;

typedef pair<ll,ii> iii; //valor,i,j

int main(){
	int n, k;
	scanf("%d %d",&n,&k);
	
	int ar[n];
	for(int i= 0 ;i<n ;i++) scanf("%d",&ar[i]);

	vector<iii> vec(n*(n-1)>>1);
	int pos = 0;
	for(int i= 0 ;i< n;i++)
		for(int j= i+1 ;j< n ;j++)
			vec[pos++] = {ar[i]+ar[j],{i+1,j+1}};
	sort(ALL(vec));
	int i= 0;
	// for(auto d:vec) cout<<(i++)<<": "<<d.first<<" "<<d.second.first<<" "<<d.second.second<<endl; cout<<endl;

	for(auto u : vec){
		ll val = u.first;
		int c = u.second.first;

		int d = u.second.second;
		ll want = k-val;
		auto pos = (upper_bound(vec.begin(),vec.end(),iii(want,{-1,-1})));
		
		if(pos==vec.end()) continue;

		int p = pos-vec.begin();
		int cont = 0;
		while(p<vec.size()){
			if(vec[p].first != want || cont > 4) break;
			int a = vec[p].second.first;
			int b = vec[p].second.second;
			if(!(a == c or a==d or b == c or b == d)){
				printf("%d %d %d %d\n",a,b,c,d);
				return 0;
			}
			p++;
			cont++;
		}
		
	}
	printf("IMPOSSIBLE\n");
	return 0;
}