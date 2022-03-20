#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;

int main(){
	string s;
	cin>>s;
	sort(ALL(s));
	vector<string>ar;
	while(1){
		ar.push_back(s);	
		if(!next_permutation(ALL(s))) break;
	}
	printf("%ld\n",ar.size());
	for(string s:ar) printf("%s\n",s.data());
	return 0;
}