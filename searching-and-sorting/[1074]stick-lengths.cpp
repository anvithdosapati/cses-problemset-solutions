#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	ll cnt = 0;
	for(int i=0;i<n;i++){
		cnt += abs(a[i]-a[n/2]);
	}
	cout<<cnt<<"\n";
}
