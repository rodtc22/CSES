#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;

void hanoi(int n_discos, int origen, int destino, int aux){
	if(n_discos==1) {
		// sal no mas, por que ya es el ultimo y no puedes mover mas
		printf("%d %d\n",origen,destino);	
		return;
	}
	hanoi(n_discos-1,origen,aux,destino);
	printf("%d %d\n",origen,destino);	
	hanoi(n_discos-1,aux,destino,origen);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",(1<<n)-1);
	hanoi(n,1,3,2);
	return 0;
}