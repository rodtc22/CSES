#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int oo =  1e9;
const int N = 2e5 + 5;

typedef pair<ii,int> iii;
 
//graph
int n,m;
vector<vector<char>> grid;
bool reached; //verifica si se alcanzo el inicio;

//auxiliares
int dx[] = {-1,1,0,0};
int dy[] ={0,0,-1,1};
vector<vector<int>> dist;

int x,y,a,b;
string ans;

void hunt(int i, int j){
	// if(i<0 || i>=n || j <0 || j>=m) return ;
	queue<ii>q;
	q.push({i,j});
	dist[i][j]=0;

	while(q.size()){
		ii u = q.front();
		q.pop();

		int x = u.first;
		int y = u.second;
		int d = dist[x][y];

		for(int k= 0 ;k <4 ;k++){
			int x2 = x+dx[k];
			int y2 = y+dy[k];

			if(x2<0 || x2>=n || y2 <0 || y2>=m) continue;
			if(dist[x2][y2] != -1) continue;
			if(grid[x2][y2] == '#') continue;

			ii v = {x2,y2};
			dist[x2][y2] = d+1;
			q.push(v);
		}
	}
}

void build(int i,int j,int cost){
	if(dist[i][j]==0) return;	//ya llegamos al final
	if(dist[i][j]==-1) return;	//no es una posicion valida
	for(int k = 0 ; k < 4; k++){
		int a = i+dx[k];
		int b = j+dy[k];
		if(a<0 || a>=n || b<0 || b>=m) continue; // se salio del campo
		if(dist[a][b]==cost-1){
			if(k==0)		ans.push_back('D');
			else if(k==1)	ans.push_back('U');
			else if(k==2)	ans.push_back('R');
			else			ans.push_back('L');
			build(a,b,cost-1);
			return;
		}
	}
}

int main(){
	cin>>n>>m;
	grid.assign(n,vector<char>(m));
	dist.assign(n,vector<int>(m,-1));
	for(int i= 0 ;i<n ;i++)
		for(int j= 0 ;j<m; j++){
			cin>>grid[i][j];
			if(grid[i][j]=='A') x =i,y = j;
			if(grid[i][j]=='B') a =i,b = j;
		}

	//solution
	reached = false;
	//calculo la distancia minima a ese nodo
	hunt(x,y); //buscar,perseguir,.. 

	if(dist[a][b]!=-1){
		ans = "";
		build(a,b,dist[a][b]);
		reverse(ALL(ans));
		cout<<"YES"<<endl<<dist[a][b]<<endl<<ans<<endl;
	}else{
		cout<<"NO\n";
	}
	// for(int i= 0 ;i<n ;i++) for(int j= 0 ;j<m; j++) cout<<dist[i][j]<<" \n"[j==m-1];
	return 0;
}