#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;
const int M = 1e9 + 7;

int n,c = 0;
string s;

//tienes que notar que los cambios, tienen que ver
//con la distribucion del Fenwick tree
//de la misma forma , en la que cambian los bits (posiciones)

int main(){
	cin>>n;
	s.assign(n,'0');
	cout<<s<<endl;
	for(int i= 1; i<(1<<n) ;i++){
		int pos = __builtin_popcount(i^(i-1)) - 1;
		s[pos] = (s[pos]=='0')? '1' : '0';
		cout<<s<<endl;
	}
	return 0;
}