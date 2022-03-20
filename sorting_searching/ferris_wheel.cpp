#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;

int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	multiset <int> mu;
	for(int i= 0  ;i<n  ;i++){
		int a;
		scanf("%d",&a);
		mu.insert(a);
	}
	int cont =0;
	while(mu.size()){
		//saco el mas liviano, siempre, para que sea acompaniado con uno pesado
		int w = *mu.begin();
		mu.erase(mu.begin());

		//pongo por defecto, porque si ya no hay mas, entonces se queda en end()
		auto pos = mu.end();
		if(!mu.empty()) pos = mu.upper_bound(x-w),pos--;

		cont++; // como saque un elemento entonces ya estoy usando una gondola

		//en caso de que el puntero sea un numero valido y su suma sea <= al peso de la gondola
		//entonces iran en la misma gondola y lo elimino
		if(pos!= mu.end() && *pos + w <= x)
			mu.erase(pos);
	}
	printf("%d\n",cont);
	return 0;
}