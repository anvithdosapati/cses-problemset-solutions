#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define MOD (int)(1e9+7);
int main()
{
	int n; cin>>n;
	ll cnt[n+1] = {0};
	cnt[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++){
			if(i-j<0) break;
			cnt[i] += cnt[i-j];
			cnt[i] %= MOD;
		}
	}
	cout<<cnt[n]<<"\n";
}
