#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int M = 1e9+7;
const int N = 1e6+1;

//SIEMPRE HACER UNA DP ITERATIVA, NUNCA UNA RECURSIVA
//YA QUE HACER UNA RECURSIVA, ME GASTA MUUUCHO TIEMPO EN EL memset()

vector <int> dp;
int x,oo = 1e6+6;

int main(){
	scanf("%d",&x);
	dp.resize(x+1,oo);

	//dp
	dp[0] = 0;
	for(int i=1; i <= x ;i++){
		string nro = to_string(i);
		int ndig = nro.size();
		for(int j = 0 ;j < ndig ;j++){
			int dig = nro[j]-'0';
			dp[i] = min(dp[i],dp[i-dig]+1);
		}
	}
	printf("%d\n",dp[x]);
	return 0;
}