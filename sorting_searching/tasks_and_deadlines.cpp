#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1003;

// PARA HALLAR LA SOLUCION TIENES QUE BASARTE EN EL CRITERIO DE LA
// PLANIFICACION DE HORARIOS, ESCOGIENDO QUIEN TERMINA PRIMERO, PARA 
// PODER HACER MAS TAREAS DESPUES

int main(){
	int n;
	scanf("%d",&n);
	vector<ii> ar(n);
	for(int i= 0  ;i< n;i++)
		scanf("%d %d",&ar[i].first, &ar[i].second);
	sort(ALL(ar));
	ll ac = 0;
	ll time = 0;
	for(int i= 0 ;i< n;i++){
		time += ar[i].first;
		ac += (ar[i].second-time);
	}
	printf("%lld\n",ac);
	return 0;
}