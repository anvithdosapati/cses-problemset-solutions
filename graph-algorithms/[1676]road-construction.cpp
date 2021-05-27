#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define MAX 1000000
int par[MAX];
int comp_size[MAX];
int max_cmp = 1;
 
int find_set(int a){
	if(a == par[a]) return a;
	return par[a] = find_set(par[a]);
}
 
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a==b) return;
	if(comp_size[b]>comp_size[a]) swap(a,b);
	comp_size[a] += comp_size[b];
	comp_size[b] = 0;
	par[b] = a;
	max_cmp = max(max_cmp, comp_size[a]);
}
 
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	int cmp_cnt = n;
	for(int i=0;i<n;i++){
		par[i] = i;
		comp_size[i] = 1;
	}
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		if(find_set(u)!=find_set(v)){
			union_set(u,v);
			cmp_cnt--;
		}
		cout<<cmp_cnt<<" "<<max_cmp<<"\n";
	}
}
