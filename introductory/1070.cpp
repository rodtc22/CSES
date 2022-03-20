#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;

int main(){
	int n;
	scanf("%d",&n);
	if(2<=n && n<=3) {
		printf("NO SOLUTION\n");
	}else{
		for(int i= 2 ;i<=n ;i+=2) printf("%d ",i);
		for(int i= 1; i<=n ;i+=2) printf("%d ",i);
		printf("\n");
	}
	return 0;
}