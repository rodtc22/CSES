#include <bits/stdc++.h>
using namespace std;

set <int> se;

//RECORDAR QUE UN MACRO PUEDE SUSTITUIR UNA FUNCION	
#define next(d)  {d++; if(d == se.end()){d = se.begin();} }

int main(){
	int n; 
	while(scanf("%d",&n) == 1){

		for(int i = 1 ;i<=n ;i++)
			se.insert(i);

		auto d = se.begin();	
		while(se.size()){
			next(d);
			printf("%d ",*d);

			//restableciendo el puntero al siguiente elemento
			auto dd = d;
			next(dd);
			se.erase(d);
			d = dd;
		}
		printf("\n");
	}
	return 0;
} 