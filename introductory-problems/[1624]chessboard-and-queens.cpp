#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
int a[8][8];
ll cnt = 0;
void fun(int r, int col[8], int diag1[15], int diag2[15]){
	if(r == 8){
		cnt++;
		return;
	}
	for(int c=0;c<8;c++){
		if(col[c] || diag1[r+c] || diag2[7+r-c] || a[r][c]) continue;
		col[c] = diag1[r+c] = diag2[7+r-c] = 1;
		fun(r+1,col,diag1,diag2);
		col[c] = diag1[r+c] = diag2[7+r-c] = 0;
	}
}
int main()
{
	int col[8] = {0};
	int diag1[15] = {0};
	int diag2[15] = {0};
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			char temp;
			cin>>temp;
			if(temp=='.') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}
	fun(0,col,diag1,diag2);
	cout<<cnt<<"\n";
}
