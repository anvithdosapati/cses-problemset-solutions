#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
const ll MAX = (ll)(1e18);
 
void dijkstra(vector<pair<int,int>> graph[], int n, vector<ll> &d, int a){
	d.assign(n,MAX);
	d[a] = 0;
	int vis[n] = {0};
	for(int i=0;i<n;i++){
		int v = -1;
		for(int j=0;j<n;j++){
			if(!vis[j] && (v==-1 || d[j]<d[v])) v = j;
		}
		vis[v] = 1;
		if(d[v]==MAX) break;
		for(auto i:graph[v]){
			ll len = i.second;
			int to = i.first;
			if(d[to]> len+d[v]){
				d[to] = d[v] + len;
			}	
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m,q; cin>>n>>m>>q;
	vector<pair<int,int>> graph[n];
	for(int i=0;i<m;i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		t1--;t2--;
		graph[t1].pb({t2,t3});
		graph[t2].pb({t1,t3});
	}
	vector<ll> d[n];
	for(int i=0;i<n;i++){
		dijkstra(graph, n, d[i], i);
	}
	for(int i=0;i<q;i++){
		int a,b; cin>>a>>b;
		a--;b--;
		if(d[a][b]==MAX) cout<<"-1\n";
		else cout<<d[a][b]<<"\n";
	}
}
