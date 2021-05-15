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
	ll n; cin>>n;
	while(n!=1){
		cout<<n<<" ";
		if(n&1) n = n*3 +1;
		else n = n>>1;
	}
	cout<<n<<"\n";
}
