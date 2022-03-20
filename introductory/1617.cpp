#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;

int main(){
	int n;
	scanf("%d",&n);
	int ans = 1;
	for(int i= 0 ;i< n ;i++)
		ans = (ans<<1)%M; 
	printf("%d\n",ans);
	return 0;
}