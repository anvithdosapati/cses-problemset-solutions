#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
 
void dijkstra(vi graph[], int n, vi &d, vi &p){
	set<pair<int,int>> s;
	s.insert({0,0});
	d[0] = 0;
	while(!s.empty()){
		int next = s.begin()->second;
		s.erase(s.begin());
		for(auto i:graph[next]){
			int to = i;
			if(d[to]>d[next]+1){
				s.erase({d[to],to});
				d[to] = d[next]+1;
				s.insert({d[to],to});
				p[to] = next;
			}
		}
	}
}
 
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	vi graph[n];
	for(int i=0;i<m;i++){
		int t1,t2;
		cin>>t1>>t2;
		t1--;t2--;
		graph[t1].pb(t2);
		graph[t2].pb(t1);
	}
	vi d(n,1000000);
	vi p(n,-1);
	dijkstra(graph, n, d, p);
	vi path;
	int t = n-1;
	while(1){
		path.pb(t);
		if(t==0) break;
		t = p[t];
	}
	if(d[n-1]==1000000){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	cout<<d[n-1]+1<<"\n";
	for(int i=path.size()-1;i>=0;i--) cout<<path[i]+1<<" ";
	printf("\n");
}
