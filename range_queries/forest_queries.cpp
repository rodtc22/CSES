#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x)  x.begin(),x.end()
#define PRINT(x) {for(auto d : x) cout<<d<<" ";cout<<endl;}
typedef long long ll;
typedef pair<int,int> ii;
const ll oo =  1e15;
const int N = 2e5 + 5;
const int M = 1e9+7;

int main(){
	int n,q;
	char c;
	scanf("%d %d",&n,&q);

	getchar();
	int grid[n][n]={};
	for(int i= 0 ;i < n;i++){
		for(int j = 0 ;j < n; j++){
			scanf("%c",&c);
			grid[i][j] = (c=='*');
		}
		getchar();
	}


	//precomputando sum-preffix
	for(int i= 1 ;i<n; i++)
		for(int j = 0 ;j < n;j++)
			grid[i][j] += grid[i-1][j];

	for(int i= 0 ; i < n;i++)
		for(int j= 1 ;j< n;j++)
			grid[i][j] += grid[i][j-1];

	
	int x1,y1,x2,y2;
	while(q--){
		scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
		y1--,x1--,x2--,y2--;

		int a = grid[y2][x2];
		int b = (y1==0)? 0 : grid[y1-1][x2];
		int c = (x1==0)? 0 : grid[y2][x1-1];
		int d = (y1==0 || x1==0)? 0 : grid[y1-1][x1-1];

		int ans = a-b-c+d;
		printf("%d\n",ans);
	}
	return 0;
}