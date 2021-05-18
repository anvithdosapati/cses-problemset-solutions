#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
 
ll prims(vector<pair<int,int>> graph[], int n, vi &path){
	int vis[n] = {0};
	int st = 0;
	int cnt = -1;
	set<pair<int,int>> s;
	s.insert({0,st});
	ll minwt = 0;
	while(!s.empty()){
		if(cnt==n-1) break;
		int len = s.begin()->first;
		int next = s.begin()->second;
		s.erase(s.begin());
		if(vis[next]==1) continue;
		vis[next] = 1;
		path.pb(next);
		cnt++;
		minwt += len;
		for(auto it:graph[next]){
			int to = it.first;
			int len = it.second;
			s.insert({len,to});
		}
	}
	return minwt;
}
 
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	vector<pair<int,int>> graph[n];
	for(int i=0;i<m;i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		t1--;t2--;
		graph[t1].pb({t2,t3});
		graph[t2].pb({t1,t3});
	}
	vi path;
	ll wt = prims(graph, n, path);
	if(path.size()!=n){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	cout<<wt<<"\n";
}
