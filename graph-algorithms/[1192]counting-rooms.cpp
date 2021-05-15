#include <bits/stdc++.h>
using namespace std;
 
char grid[1001][1001];
int visit[1001][1001];
int n,m;
 
void fill(int r, int c, char type){
	if(r<0 || r>=n || c<0 || c>=m) return;
	if(grid[r][c]!=type) return;
	if(visit[r][c]==1) return;
	visit[r][c] = 1;
	fill(r,c+1,type);
	fill(r,c-1,type);
	fill(r-1,c,type);
	fill(r+1,c,type);
}
int main()
{
	int cnt = 0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>grid[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visit[i][j]==0){
				fill(i,j,grid[i][j]);
				if(grid[i][j]=='.') cnt++;
			}
		}
	}
	cout<<cnt<<"\n";
}
