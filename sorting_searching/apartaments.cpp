#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

/*idea clave, tomar el que esta mas a la izquierda
para que el siguiente tenga mas posibilidad de tener 
un departamento, y como vamos a eliminar y va a haber 
repetidos entonces voy a usar un muliset*/

int main(){
	int n,m,k,x;
	scanf("%d %d %d",&n,&m,&k);
	multiset<int> aplicant,apartament;
	
	for(int i= 0; i< n;i++){
		scanf("%d",&x);
		aplicant.insert(x);
	}

	for(int i= 0; i< m;i++){
		scanf("%d",&x);
		apartament.insert(x);
	}

	//usaremos variacion de busqueda binaria para halla eficientemente
	//el mas disponible de la izquierda

	int cont = 0;

	for(int a:aplicant){
		if(apartament.empty()) break;

		auto stat = apartament.lower_bound(a-k);
		if( stat != apartament.end() and (a-k <= *stat and *stat <= a+k)){
			//significa que si hay y esta en el rango permititdo
			cont++;
			apartament.erase(stat);
		}
	}
	printf("%d\n",cont);
	return 0;
}