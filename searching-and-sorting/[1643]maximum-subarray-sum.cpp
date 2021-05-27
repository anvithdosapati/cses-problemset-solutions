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
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n; cin>>n;
	ll a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	ll dp[n];
	dp[0] = a[0];
	ll best = dp[0];
	for(int i=1;i<n;i++){
		dp[i] = max(dp[i-1]+a[i], a[i]);
		best = max(best, dp[i]);
	}
	cout<<best<<"\n";
}
