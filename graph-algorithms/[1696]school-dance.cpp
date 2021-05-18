#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<vi> vvi;
 
#define ff first
#define ss second
#define pb push_back
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
int n,m,k;
 
// Dinics from "https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/Dinic.h"
struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); }
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	void calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do {
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		cout<<flow<<"\n";
		for(int i=1;i<=n;i++){
			for(Edge e:adj[i]){
				if(e.to==n+m+1) continue;
				if(e.flow()>0){
					cout<<i<<" "<<e.to-n<<"\n";
				}
			}
		}
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};
 
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	Dinic Din(n+m+2);
	for(int i=0;i<k;i++){
		int u,v; cin>>u>>v;
		Din.addEdge(u,n+v,1);
	}
	for(int i=1;i<=n;i++) Din.addEdge(0,i,1);
	for(int i=1;i<=m;i++) Din.addEdge(i+n,n+m+1,1);
	Din.calc(0,n+m+1);
}
