#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
const ll MAX = (ll)(1e18);
 
void dijkstra(vector<pair<int,int>> graph[], int n, vector<ll> &d, int a){
	d[a] = 0;
	set<pair<ll,int>> s;
	s.insert({0,a});
	while(!s.empty()){
		int cur = s.begin()->second;
		s.erase(s.begin());
		for(auto i:graph[cur]){
			ll len = i.second;
			int v = i.first;
			if(d[v]> len+d[cur]){
				s.erase({d[v],v});
				d[v] = d[cur] + len;
				s.insert({d[v],v});
			}	
		}
	}
}
 
int main()
{
	int n,m; cin>>n>>m;
	vector<pair<int,int>> graph[n];
	for(int i=0;i<m;i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		t1--;t2--;
		graph[t1].pb({t2,t3});
	}
	vector<ll> d(n, MAX);
	dijkstra(graph, n, d, 0);
	for(int i=0;i<n;i++){
		cout<<d[i]<<" ";
	}
	printf("\n");
}
