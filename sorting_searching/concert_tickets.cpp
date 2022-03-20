#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(){
	int x,n,m;
	scanf("%d %d",&n,&m);
	multiset<int> ticket;
	
	for(int i= 0 ;i< n;i++){
		scanf("%d",&x);
		ticket.insert(x);
	}
	for(int i= 0 ;i< m ;i++){
		scanf("%d",&x);

		auto pos= ticket.end();
		if(ticket.size()) pos = --ticket.upper_bound(x);

		if(pos!=ticket.end() and *pos <= x){
			printf("%d\n",*pos);
			ticket.erase(pos);
		}else{
			printf("-1\n");
		}
	}


	return 0;
}