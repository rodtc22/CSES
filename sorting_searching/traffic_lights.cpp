#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(){
	int x,n;
	scanf("%d %d",&x,&n);
	int l = 0, r = x;
	
	vector<int> ans;
	//todos los intervalos van a ser distintos, ademas
	// voy a necesitar upper_bound();
	set<ii>interval;

	//voy a tener distancias repetidas y voy a necestiar lower_bound()
	multiset<int> dist;

	interval.insert({r,l});
	dist.insert(r-l);
	while(n--){
		scanf("%d",&x);
		
		//saco el intervalo en que se encuentra el nro
		auto pos = interval.upper_bound({x,-1});
		ii nros = *pos;
		interval.erase(pos);

		//saco una distancia que tenga ese intervalo
		auto disto = dist.lower_bound(nros.first-nros.second);
		dist.erase(disto);

		//lo parto en 2 y los vuelvo a adicionar
		interval.insert({x,nros.second});
		interval.insert({nros.first,x});
		dist.insert(x-nros.second);
		dist.insert(nros.first-x);

		printf("%d ",*(--dist.end()));
	}
	printf("\n");
	return 0;
}