#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
//priorizar la salida,entrada,habitacion

int main(){
	int q,in,out;
	scanf("%d",&q);

	priority_queue<iii> pq;
	priority_queue <int,vector<int>,greater<int>>  rooms;
	vector<ii> ans;
	vector<iii> ar(q);
	int i = 0;
	for(auto &d:ar) scanf("%d %d",&d.first.first,&d.first.second),d.second = i++;
	sort(ALL(ar));
	// for(auto d:ar) cout<<d.first.first<<" "<<d.first.second<<" "<<d.second<<endl;cout<<endl;

	int nroRoom = 1;

	for(auto d:ar){
		in = d.first.first,out = d.first.second;

		if(pq.size()){
			//tiene habitaciones que podrian desocuparse
			while(pq.size()){
				iii x = pq.top();
				int salida = -x.first.first;
				
				if(salida >= in) break;
				
				pq.pop();
				rooms.push(x.second);
			}
		}

		if(rooms.empty())
			rooms.push(nroRoom++);
		
		ans.push_back({d.second,rooms.top()});
		pq.push({{-out,in},rooms.top()});
		rooms.pop();
	}
	int maxi = 0;
	for(ii d:ans) maxi = max(maxi,d.second);
		sort(ALL(ans));
	printf("%d\n",maxi);
	for(int i=0 ;i < ans.size(); i++) printf("%d ",ans[i].second);
	printf("\n");
	return 0;
}