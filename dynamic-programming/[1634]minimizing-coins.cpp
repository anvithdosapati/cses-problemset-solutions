#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
 
const int MAX = (int)(1e6+10);
int main()
{
	int n,x;
	cin>>n>>x;
	int c[n];
	int minc = MAX;
	for(int i=0;i<n;i++){
		cin>>c[i];
		minc = min(minc, c[i]);
	}
	int dp[x+1];
	if(x<minc){
		cout<<"-1\n";
		return 0;
	}
	dp[0] = 0;
	for(int i=1;i<minc;i++){
		dp[i] = -1;
	}
	dp[minc] = 1;
	for(int i=minc+1;i<=x;i++){
		int minn = MAX;
		for(int j=0;j<n;j++){
			int temp = -1;
			if(i<c[j] || dp[i-c[j]]==-1) continue;
			temp = dp[i-c[j]] + 1;
			minn = min(minn, temp);
		}
		if(minn==MAX) dp[i] = -1;
		else dp[i] = minn;
	}
	cout<<dp[x]<<"\n";
}
