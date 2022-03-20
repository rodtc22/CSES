#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;

char chess[8][8];
int queen[8];
int n = 8,cont = 0;

bool valid(int row, int col){
	// si es * entonces no podemos poner una reina
	if(chess[row][col]=='*') return 0; 

	for(int i= 0 ;i< n;i++){
		// si alguien ya tiene ocupada esa columna entonces no sirve
		if(queen[i] == col) return 0; 

		// si tiene la misma distancia hamming con alguien (esta en la misma diagonal) y 
		// esa posicion esta ocupada entonces NO PODEMOS PONER UNA REINA
		if(queen[i]!=-1 && abs(i-row)==abs(queen[i]-col)) return 0; 
	}
	return 1;
}

void ways(int row){
	if(row==n){
		cont++;  // si pudo llegar hasta aqui entonces si se pudo, contamos y nos salimos
		return;
	}

	for(int i= 0 ;i< n; i++){
		if(!valid(row,i)) continue;  //verifica si puede estar en esa posicion

		queen[row] = i;  // marcamos para mostrar que estamos usando esa posicion
		ways(row+1);	// voy por la siguiente reina
		queen[row] = -1; // quito a la reina de esa posicion
	}
}

int main(){
	for(int i= 0 ; i< n ;i++)
		for(int j= 0 ;j<n ;j++)
			cin>>chess[i][j];
	memset(queen,-1,sizeof queen);
	ways(0);
	cout<<cont<<endl;
	return 0;
}