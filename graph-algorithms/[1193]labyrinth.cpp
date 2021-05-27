#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<vi> vvi;
 
#define ff first
#define ss second
#define pb push_back
 
int main()
{
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	char a[n][m];
	int si,sj,ei,ej;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]=='A'){
				si = i; sj = j;	
			}
			if(a[i][j]=='B'){
				ei = i; ej = j;
			}
		}
	}
	queue<pair<int,int>> que;
	que.push({si,sj});
	int vis[n][m];
	int dis[n][m];
	pair<int,int> prev[n][m];
	vis[si][sj] = 1;
	dis[si][sj] = 0;
	prev[si][sj] = {-1,-1};
	char dir[n][m];
	memset(vis, 0, n*m*sizeof(int));
	memset(dis, 0, n*m*sizeof(int));
	memset(dir, '0', n*m*sizeof(char));
	while(!que.empty()){
		int ci = que.front().ff;
		int cj = que.front().ss;
		que.pop();
		for(int i=0;i<4;i++){
			int di = dx[i];
			int dj = dy[i];
			if(ci+di>=n || cj+dj>=m || ci+di<0 || cj+dj<0) continue;
			if(a[ci+di][cj+dj]=='#') continue;
			if(vis[ci+di][cj+dj]!=1){
				vis[ci+di][cj+dj] = 1;
				que.push({ci+di,cj+dj});
				dis[ci+di][cj+dj] = dis[ci][cj]+1;
				prev[ci+di][cj+dj] = {ci,cj};
				if(di==1) dir[ci+di][cj+dj] = 'D';
				if(di==-1) dir[ci+di][cj+dj] = 'U';
				if(dj==1) dir[ci+di][cj+dj] = 'R';
				if(dj==-1) dir[ci+di][cj+dj] = 'L';
			}
		}
	}
	if(vis[ei][ej]==0){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	int d = dis[ei][ej];
	vector<char> path;
	int x = ei, y = ej;
	for(int i=0;i<d;i++){
		path.pb(dir[x][y]);
		int nx = prev[x][y].ff;
		int ny = prev[x][y].ss;
		x = nx; y = ny;
	}
	cout<<d<<"\n";
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i];
	}
	cout<<"\n";
}
