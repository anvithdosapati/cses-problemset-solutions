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
	int n,x; cin>>n>>x;
	int a[n];
	map<int,int> m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m[a[i]] = i;
	}
	for(int i=0;i<n;i++){
		if(m.count(x-a[i])){
			if(i!=m[x-a[i]]){
				cout<<i+1<<" "<<m[x-a[i]]+1<<" ";
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE\n";
}
