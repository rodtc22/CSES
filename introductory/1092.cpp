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
	ll nro  = (1LL*n*(n+1))>>1;
	if(nro&1){
		printf("NO\n");
	}else{
		printf("YES\n");
		int vec[n+1]={};
		int pos = n;
		int cont = 0;
		nro >>= 1;
		while(nro>0){
			if(pos<=nro){
				vec[pos] = 1;
				nro -=pos;
				cont++;
			}
			pos--;
		}
		printf("%d\n",cont);
		for(int i= 1; i<=n ;i++)
			if(vec[i]==1)
				printf("%d ",i);
		printf("\n");
		printf("%d\n",n-cont);
		for(int i= 1; i<=n ;i++)
			if(vec[i]==0)
				printf("%d ",i);
		printf("\n");
	}
	return 0;
}