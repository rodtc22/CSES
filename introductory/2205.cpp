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

void f(int i){
	if(i==n) cout<<s.substr(1,s.size())<<'\n',c++;
	else{
		f(i+1);
		s[i+1] = (s[i+1]=='0')? '1':'0';
		f(i+1);
	}
}

int main(){
	cin>>n;
	s.assign(n+1,'0');
	f(0);
	// cout<<"cont: "<<c<<endl;
	return 0;
}