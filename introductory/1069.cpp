#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;

int main(){
	string s;
	char ant = 'a';
	cin>>s;
	s.push_back('Z');
	int ans = 0, cont = 0;
	for(char c:s){
		if(c==ant){
			cont++;
		}else{
			if(ant == 'A' or ant == 'C' or ant == 'G' or ant == 'T')
				ans = max(ans,cont);
			cont = 1;
		}
		ant = c;
	}
	printf("%d\n",ans);
	return 0;
}