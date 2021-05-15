#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
 
int vis1[1000000] = {0};
int vis2[1000000] = {0};
 
vi order;
vector<int> graph[1000000];
vector<int> grapht[1000000];
 
void dfs1(int x){
	if(vis1[x]) return;
	vis1[x] = 1;
	for(auto it:graph[x]) dfs1(it);
	order.pb(x);
}
 
void dfs2(int x, vi &comp){
	if(vis2[x]) return;
	vis2[x] = 1;
	comp.pb(x);
	for(auto it:grapht[x]) dfs2(it, comp);
}
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++){
		int t1,t2;
		cin>>t1>>t2;
		t1--;t2--;
		graph[t1].pb(t2);
		grapht[t2].pb(t1);
	}
	for(int i=0;i<n;i++){
		if(!vis1[i]) dfs1(i);
	}
	int king[n];
	int k=0;
	for(int i=n-1;i>=0;i--){
		vi comp;
		if(vis2[order[i]]) continue;
		k++;
		dfs2(order[i],comp);
		for(auto it:comp) king[it] = k;
	}
	cout<<k<<"\n";
	for(int i=0;i<n;i++) cout<<king[i]<<" ";
	printf("\n");
}
