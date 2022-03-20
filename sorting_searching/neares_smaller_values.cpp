#include <bits/stdc++.h>
using namespace std;
 
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1003;

//la idea clave es entender que es una funcion monotona
//la clave es usar una monotonic stack

int main(){
	int n;
	scanf("%d",&n);
	int ar[n];
	for(int i= 0 ;i< n;i++) scanf("%d",&ar[i]);

	stack<int> pos;
	int p = 0;
	for(int i= 0 ;i< n; i++){
		while(pos.size() && ar[pos.top()] >= ar[i]) pos.pop();

		if(pos.size()) p = pos.top()+1;
		else p = 0;
		printf("%d ",p);
		
		pos.push(i);
	}
	printf("\n");
	return 0;
}