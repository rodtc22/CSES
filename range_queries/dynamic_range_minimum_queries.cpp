#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;
const int N = 2e5 + 5;
const int M = 1e9+7;

//indexado desde cero
struct SegmenTree{
	SegmenTree *left,*right;
	int l,r,m;
	ll valor,neutro = 1e15;  //neutro = oo

	//crea todo el segment tree
	SegmenTree(int l,int r) : l(l),r(r),valor(neutro){
		if(l != r){
			m = (l+r)>>1;
			left = new SegmenTree(l,m);
			right = new SegmenTree(m+1,r);
		}
	}

	void update(int pos, ll val){
		if(l==r){
			valor = val;
		}else{
			if(pos <= m){ // buscando a la izq
				left->update(pos,val);
			}else{
				right->update(pos,val);
			}
			valor = min(left->valor, right->valor);
		}
	}

	ll query(int a, int b){
		if(a > r || b < l) return neutro;
		if(a<= l && r <= b) return valor;
		return min(left->query(a,b) , right->query(a,b));
	}

};

int main(){
	int n,q;
	scanf("%d %d",&n,&q);

	vector<ll> ar(n);
	for(ll &d:ar) scanf("%lld",&d);

	//rango que maneja el nodo raiz[0,n-1]
	SegmenTree st(0,n-1);
	for(int i = 0 ;i < n;i++)
		st.update(i,ar[i]);

	int op,a,b;
	while(q--){
		scanf("%d %d %d",&op,&a,&b);
		if(op == 1){ // actualizar pos-a con b
			st.update(a-1,b);
		}else{
			ll ans = st.query(a-1,b-1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}