#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e6+6;

//g++ -std=c++11 -02 main.cpp -o main -Wall

int memo[N];

int f(int x){
	if(x<0) return 0;
	if(x==0) return 1;

	int &ans = memo[x];
	if(ans != -1) return ans;

	ans = 0;
	for(int i = 1 ;i<=6 ;i++)
		ans = (ans + f(x-i))%M;
	return ans;
}

int main(){
	int x; cin>>x;
	memset(memo,-1,sizeof memo);
	cout<<f(x)<<endl;
	return 0;
}