#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e6+6;

int items[102];
int target[N];
int n,k;

int f(int x){
	if(x<0) return 0;
	if(x==0) return 1;

	int &ans = target[x];
	if(ans != -1) return ans;

	ans = 0;
	for(int i = 0 ;i<n ;i++)
		ans = (ans + f(x-items[i]))%M;
	return ans;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i= 0 ;i< n ;i++) scanf("%d",&items[i]);
	memset(target,-1,sizeof target);
	int ans = f(k);
	printf("%d\n",ans);
	return 0;
}