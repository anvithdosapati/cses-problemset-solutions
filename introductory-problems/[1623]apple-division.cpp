#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
int main()
{
	int n; cin>>n;
	int p[n];
	for(int i=0;i<n;i++) cin>>p[i];
	ll best = (int)(1e18);
	for(int i=0;i<(1<<n);i++){
		ll sum1=0;
		ll sum2=0;
		for(int l=0;l<n;l++){
			if(i&(1<<l)) sum1 += p[l];
			else sum2 += p[l];
		}
		best = min(best, abs(sum1-sum2));
	}
	cout<<best<<"\n";
}
