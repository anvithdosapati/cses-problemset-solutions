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
	for(int i=0;i<n;i++) cin>>a[i];
	int sum = 0;
	int p1 = 0;
	int cnt = 0;
	for(int p2=0;p2<n;p2++){
		sum += a[p2];
		while(sum-a[p1]>=x){
			sum -= a[p1];
			p1++;
		}
		if(sum == x){
			cnt++;
		}
	}
	cout<<cnt<<"\n";
}
