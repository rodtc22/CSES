#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;

int main(){
	int n;
	scanf("%d",&n);
	vector<ii>ar(n);
	for(int i= 0 ;i <n; i++){
		scanf("%d",&ar[i].first);
		ar[i].second = i+1;
	}
	sort(begin(ar),end(ar));
	ar.push_back({-1,-1});

	int cont = 0;
	int ant =0;
	for(auto d:ar){
		if(d.second < ant) 
			cont++;
		ant = d.second;
	}
	printf("%d\n",cont);
	return 0;
}