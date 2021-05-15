#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
int main()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	ll cnt =0;
	do{
		cnt++;
	}while(next_permutation(s.begin(),s.end()));
	cout<<cnt<<"\n";
	do{
		cout<<s<<"\n";
	}while(next_permutation(s.begin(),s.end()));
}
