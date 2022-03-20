#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;

//USANDO TWO POINTERS

int main(){
	int n;
	scanf("%d",&n);
	int ar[n];
	for(int i= 0 ;i < n ;i++) scanf("%d",&ar[i]);

	int a =0,b = 0;
	set<int> se;

	int ans = 0;
	for(b = 0; b < n ;b++){
		if(se.find(ar[b]) == se.end()){
			se.insert(ar[b]);
		}else{
			while(ar[a++] != ar[b])
				se.erase(ar[a-1]);
		}
		ans =max(ans,int(se.size()));
	}
	printf("%d\n",ans);
}