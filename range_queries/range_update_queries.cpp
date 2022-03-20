#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;
const int N = 2e5 + 5;
const int M = 1e9+7;

struct SegmenTreeLazy{
	SegmenTreeLazy *left,*right;
	int l,r,m;
	ll valor, neutro = 0; // ya que manejaremos suma
	ll lazy; //0:ya propago,  !=0 : falta propagar

	SegmenTreeLazy(int l, int r) : l(l),r(r),valor(neutro),lazy(neutro){
		if(l!=r){
			m = (l+r)>>1;
			left = new SegmenTreeLazy (l,m);
			right = new SegmenTreeLazy(m+1,r);
		}
	}

	/*yo voy a tomar lazy == 0 por que si tengo que actualizar cero
	a mis nodos hijo, es como no actualizar nada ya que x + 0 = x*/
	void propagate(){
		if(lazy != 0){ 
			int tam = r-l+1;
			valor += (lazy*tam);
			if(l!=r){
				left->lazy += lazy;
				right->lazy += lazy;
			}
			lazy = 0;
		}
	}

	ll query(int a, int b){
		propagate();
		if(a>r || b < l) return neutro;
		if(a<=l && r<=b) return valor;
		return left->query(a,b) + right->query(a,b);
	}

	void update(int a, int b, ll val){
		propagate();
		if(a>r || b <l) return;
		if(a <= l && r <= b){
			lazy = val;
			propagate(); // avisa a tus dos nodos hijos
			return;
		}
		left->update(a,b,val);
		right->update(a,b,val);
		valor =  left->valor + right->valor;
	}
};

int main(){
	int n,q;
	scanf("%d %d ",&n,&q);
	vector<ll> ar(n);

	for(ll &d:ar) scanf("%lld",&d);

	SegmenTreeLazy st(0,n-1); //[l,r]
	for(int i= 0 ; i< n;i++) st.update(i,i,ar[i]);

	int op,x,a,b;
	while(q--){
		scanf("%d",&op);
		if(op==2){
			scanf("%d",&x);
			printf("%lld\n",st.query(x-1,x-1));
		}else{
			scanf("%d %d %d",&a,&b,&x);
			st.update(a-1,b-1,x);
		}
	}
}