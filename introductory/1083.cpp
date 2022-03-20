#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;

int main(){
	bool ar[N]={};
	int n ; scanf("%d",&n);
	for(int i= 0 ;i < n-1; i++){
		int x;
		scanf("%d",&x);
		ar[x]=1;
	}
	for(int i= 1; i<=n ;i++)
		if(!ar[i])
			printf("%d\n",i);
	return 0;
}