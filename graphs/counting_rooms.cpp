#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int oo =  1e9;
const int N = 2e5 + 5;
 
int n,m;
vector<vector<char>>grid;

int cont = 0;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void visit(int i, int j){
	if(i<0 || i >=n || j < 0 || j>=m) return; // se salio del mapa
	if(grid[i][j]=='#') return; 	//si es pared, ya no puedo visitar

	grid[i][j] = '#';
	for(int k= 0 ;k <4 ;k++)
		visit(i+dx[k],j+dy[k]);
}

int main(){
	cin>>n>>m;
	grid.assign(n,vector<char>(m));
	for(int i= 0 ;i<n ;i++) 
		for(int j= 0 ;j<m ;j++)
			cin>>grid[i][j];

	//solve
	cont = 0;
	for(int i= 0 ;i<n; i++){
		for(int j=  0 ;j<m ;j++){
			if(grid[i][j]=='.'){
				cont++;
				visit(i,j); // marcarlo como pasado
			}
		}
	}

	cout<<cont<<endl;
	return 0;
}