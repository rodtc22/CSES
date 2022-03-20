#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,x;
	scanf("%d",&n);
	set<int>se;
	while(n--){
		scanf("%d",&x);
		se.insert(x);
	}
	printf("%ld\n",se.size());
	return 0;
}
