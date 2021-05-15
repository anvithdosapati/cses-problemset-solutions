#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define MAX_N (int)(2*1e5)
int a[MAX_N];
vi tree[MAX_N];
int dfs(int c, int p){
	int cnt = 1;
	for(auto it:tree[c]){
		if(it == p) continue;
		cnt += dfs(it, c);
	}
	a[c] = cnt;
	return cnt;
}
int main()
{
	int n; cin>>n;
	for(int i=1;i<n;i++){
		int tmp; cin>>tmp;
		tree[i].pb(tmp-1);
		tree[tmp-1].pb(i);
	}
	dfs(0,0);
	for(int i=0;i<n;i++){
		cout<<a[i]-1<<" ";
	}
}
