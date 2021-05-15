#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
 
vi graph[(int)(1e5)];
int visit[(int)(1e5)] = {0};
bool color[(int)(1e5)];
 
int f = 0;
void dfs(int x, bool col){
	if(visit[x]==1){
		if(color[x]!=col) return;
		else{
			f = 1;
			return;
		}
	}
	else{
		color[x] = !col;
		visit[x] = 1;
		for(auto it:graph[x]) dfs(it, color[x]);
	}
}
int main()
{
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b; cin>>a>>b;
		graph[a-1].pb(b-1);
		graph[b-1].pb(a-1);
	}
	for(int i=0;i<n;i++){
		if(visit[i]==0){
			dfs(i,false);
		}
	}
	if(f) cout<<"IMPOSSIBLE\n";
	else{
		for(int i=0;i<n;i++){
			if(color[i]) cout<<"1 ";
			else cout<<"2 ";
		}
		cout<<"\n";
	}
}
