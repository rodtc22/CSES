#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e8;
const int N = 2e5 + 5;
const int M = 1e9+7;

/*de este ejercicio aprendi que consultar cosas ovbias, como
verificar si una posicion del visit, esta encendida.
puede consumir harto tiempo en un problema de este tipo
por que en lugar de hacer 3*n consultas, hacia 4*n*/

// ESTE PROBLEMA SE RESUELVE USANDO RAMIFICACION Y PODA

//en ocaciones los define pueden ahorrarnos un if
#define valido(a,l,r) (l<=a && a <=r)
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

string path;
bool visit[7][7]={};


int caminos(int i, int j,int cont){

	if(cont == 48) return i==6 && j == 0;

	if(i==6 && j == 0) return 0;
	
	if(visit[i][j]) return 0;	// esta en una casilla visitada

	//cuando lo divide en 2 componentes horizonta-vertical
	bool adj[]={1,1,1,1}; //0: libre    1: ocupado
	for(int k = 0 ;k < 4; k++)
		if(valido(i+dy[k],0,6) && valido(j+dx[k],0,6))
			adj[k] = visit[i+dy[k]][j+dx[k]];

	if(adj[UP] && adj[DOWN] && !adj[LEFT] && !adj[RIGHT]) return 0;

	if(!adj[UP] && !adj[DOWN] && adj[LEFT] && adj[RIGHT]) return 0;

	//cuando lo divide en 2 componentes diagonal
	if(valido(i-1,0,6) && valido(j-1,0,6)){
		if((visit[i-1][j-1] && !visit[i-1][j] && !visit[i][j-1]) )
			return 0;
	}

	if(valido(i-1,0,6) && valido(j+1,0,6)){
		if((visit[i-1][j+1] && !visit[i-1][j] && !visit[i][j+1]) )
			return 0;
	}

	if(valido(i+1,0,6) && valido(j-1,0,6)){
		if((visit[i+1][j-1] && !visit[i+1][j] && !visit[i][j-1]) )
			return 0;
	}

	if(valido(i+1,0,6) && valido(j+1,0,6)){
		if((visit[i+1][j+1] && !visit[i+1][j] && !visit[i][j+1]) )
			return 0;
	}

	int ans = 0; // donde se almacena la respuesta de los cuatro lados
	visit[i][j] = 1;
	if(path[cont]=='?'){
		for(int k= 0 ;k  < 4 ; k++){
			if(valido(i+dy[k],0,6) && valido(j+dx[k],0,6) && !visit[i+dy[k]][j+dx[k]]){
				ans += caminos(i+dy[k],j+dx[k],cont+1);
			}
		}
	}else{
		if(path[cont] == 'L' && valido(j-1,0,6)) ans = caminos(i,j-1,cont+1);
		else if(path[cont] == 'R' && valido(j+1,0,6)) ans = caminos(i,j+1,cont+1);
		else if(path[cont] == 'U' && valido(i-1,0,6)) ans = caminos(i-1,j,cont+1);
		else if(path[cont] == 'D' && valido(i+1,0,6)) ans = caminos(i+1,j,cont+1);
	}
	visit[i][j] = 0;
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie();
	cin>>path;
	int ans = caminos(0,0,0);
	cout<<ans<<endl;
	return 0;
}
