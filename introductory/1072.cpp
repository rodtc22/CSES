#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long ll;
const int N = 200005;

int main(){
	int n;
	cin>>n;
	ll nro = 0,x;
	for(ll k= 1; k<=n ;k++){
		ll a = ((k*k)*((k*k)-1)/2);
		ll b = ((4*k)-6)*(k-2);
		ll c = (2*k)-4;
		// cout<<a<<" "<<b<<" "<<c<<endl;
		cout<< a - b - c <<endl;
	}
	return 0;
}