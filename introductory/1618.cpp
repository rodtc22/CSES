#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;

int main(){
	int n,ans = 0;
	scanf("%d",&n);
	for(int i= 5 ;i <= n ; i*=5)
		ans += (n/i);
	printf("%d\n",ans);
	return 0;
}