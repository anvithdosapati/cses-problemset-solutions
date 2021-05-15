#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
int main()
{
	int n;
	cin>>n;
	pair<int,int> a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].second;
		cin>>a[i].first;
	}
	sort(a,a+n);
	int t =0;
	int i=0;
	int cnt = 0;
	int maxs = 0;
	for(int i=0;i<n;i++){
		if(maxs < a[i].second) maxs = a[i].second;
	}
	while(t<=maxs){
		while(t>a[i].second) i++;
		t = a[i].first;
		cnt++;
	}
	cout<<cnt<<"\n";
}
