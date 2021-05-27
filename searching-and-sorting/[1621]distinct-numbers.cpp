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
	set<int> s;
	for(int i=0;i<n;i++){
		int tmp; cin>>tmp;
		s.insert(tmp);
	}
	cout<<s.size()<<"\n";
}
