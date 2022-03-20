#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;
const int N = 2e5 + 5;
const int M = 1e9+7;


//esta es mi version de Fenwick, para que permita leer datos
//negativos
struct FenwickTree{
	int n;
	vector<ll> ar,tree;

	FenwickTree(int n1){
		n = n1;
		tree.assign(n+1,0);
		ar.assign(n+1,0);
	}

	ll query(int pos){
		ll sum = 0;
		while(pos){
			sum += tree[pos];
			pos -= (pos & (-pos));
		}
		return sum;
	}

	ll query(int l, int r){
		return query(r) - ((l==1)? 0 : query(l-1));
	}

	void update(int pos , ll val){
		ll dif = val - ar[pos];
		ar[pos] += dif;

		while(pos <= n){
			tree[pos] += dif;
			pos += (pos & (-pos));
		}
	}

	void leer(){
		//ahora leemos el vector aqui, y hacemos el init
		// de una vez

		for(int i = 1 ;i <= n;i++){
			ll x; scanf("%lld",&x);
			update(i,x);
			ar[i] = x;
		} 		
	}

	void mostrar(){
		cout<<"FenwickTree\n";
		for(int i= 1 ;i <=n ;i++) cout<<ar[i]<<" \n"[i==n];
		for(int i= 1 ;i <=n ;i++) cout<<tree[i]<<" \n"[i==n];
	}
};

int main(){
	int n,q;
	scanf("%d %d",&n,&q);

	FenwickTree f1(n);
	f1.leer();

	int op,a,b;
	while(q--){
		scanf("%d %d %d",&op,&a,&b);
		if(op == 1){ // actualizar pos-a con b
			f1.update(a,b);
		}else{
			ll ans = f1.query(a,b);
			printf("%lld\n",ans);
		}
	}
	return 0;
}