#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
struct SparceTable{
	int n,m;
	ll oo = 0; //neutro , para suma = 0, para max = -oo , para min = oo
	vector<vector<ll>> table;
 
	SparceTable(int n = 0): n(n){
		m = 32 - __builtin_clz(n);
		table.assign(n,vector<ll>(m,oo));
	}
 
	void mostrar(){
		for(auto a:table){
			for(auto b: a) cout<<b<<" ";
			cout<<endl;
		}
	}
 
	void init(vector<ll> & ar){
		for(int i= 0 ;i< n;i++) 
			table[i][0] = ar[i];
	}
 
	void create(vector<ll> & ar){
		init(ar);
		for(int j = 1 ;j < m; j++)
			for(int i= 0 ;i < n - (1<<(j-1)); i++)
				table[i][j] = table[i][j-1] + table[i+(1<<(j-1))][j-1];
	}
 
	ll query(int l, int r){
		l--,r--; 		
		int dist = r-l+1;
		int tam = 32 - __builtin_clz(dist);
 
		ll ans = 0;
		for(int i= 0 ; i < tam ;i++){
			if(dist&(1<<i)){
				ans += table[l][i] ;
				l = l + (1<<i);
			}
		}
		return ans;
	}
};
 
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	vector<ll> ar(n);
	for(ll &d: ar) scanf("%lld",&d);
 
	SparceTable st(n);
	st.create(ar);
	
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		ll ans = st.query(l,r);
		printf("%lld\n",ans);
	}
	return 0;
}