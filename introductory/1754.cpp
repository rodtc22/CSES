#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<b) swap(a,b);
		int i = a-b;
		int na = a - i*2;
		int nb = b - i;
		bool sw = 0;
		if(na>=0 && nb >=0 ){
			sw |= ((na+nb)%3==0);
		}
		printf("%s\n",sw?"YES":"NO");
	}
	return 0;
}