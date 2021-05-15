#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
 
#define pb push_back
 
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	string s; cin>>s;
	int n = s.length();
	int cnt = 1;
	int maxx = 1;
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1]) cnt++;
		else cnt = 1;
		maxx = max(maxx,cnt);
	}
	cout<<maxx<<"\n";
}
