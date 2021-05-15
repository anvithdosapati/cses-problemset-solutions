#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
 
#define MOD (int)(1e9+7)
int main()
{
	int k,n; cin>>k>>n;
	int a[k];
	for(int i=0;i<k;i++) cin>>a[i];
	int dp[n+1] = {0};
	dp[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			if(i-a[j]<0) continue;
			dp[i] = (dp[i] + dp[i-a[j]])%MOD;
		}
	}
	cout<<dp[n]<<"\n";
}
