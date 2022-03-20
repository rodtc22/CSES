#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;

int main(){
	int n;
	scanf("%d",&n);
	multiset<int> mu;
	
	while(n--){
		int x;
		scanf("%d",&x);
		auto pos = mu.end();
		if(mu.size()) pos = mu.upper_bound(x);

		if(pos!=mu.end())
			mu.erase(pos);
		mu.insert(x);
	}
	printf("%ld\n",mu.size());
}