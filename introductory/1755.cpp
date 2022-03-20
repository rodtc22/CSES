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
	int let[26]={};
	for(char c:s) let[c-'A']++;
	int n= s.size();
	bool sw = 1;
	if(n&1){
		int cont = 0;
		for(int i= 0 ;i< 26 ;i++)
			cont += (let[i]%2==1);
		sw &= (cont == 1);
	}else{
		for(int i= 0 ;i<26 ;i++)
			sw &= (let[i]%2==0);
	}
	if(sw){
		s = "";
		string t = "";
		int p = 0;
		for(int i= 0 ;i< 26 ;i++){
			
			int nro = 0;
			if(let[i]&1) nro = 0,p =  i;
			else nro = let[i]>>1,let[i]=0;

			while(nro--){
				s.push_back('A'+i);
				t.push_back('A'+i);
			}
		}

		while(let[p]--)
			s.push_back('A'+p);
		reverse(ALL(t));
		s.append(t);

		printf("%s\n",s.data());
	}else{
		printf("NO SOLUTION\n");
	}
	return 0;
}