#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
 
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n; cin>>n;
	int v[n+1] = {0};
	for(int i=0;i<n-1;i++){
		int k; cin>>k;
		v[k] = 1;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			cout<<i<<"\n";
			break;
		}
	}
}
