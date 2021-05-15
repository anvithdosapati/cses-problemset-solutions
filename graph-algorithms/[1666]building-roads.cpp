#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> graph[100010];
int visit[100010] = {0};
 
void dfs(int x){
    if(visit[x] == 1) return;
    visit[x] = 1;
    for(auto it: graph[x]){
        dfs(it);
    }
    return;
}
 
int main()
{
    int m;
    cin >>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >>x>>y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    int cnt = 0;
    vector<pair<int,int>> p;
    int c = 1;
    for(int i=0;i<n;i++){
        if(visit[i] == 0){
            p.push_back({c,i+1});
            c = i + 1;
            cnt++;
            dfs(i);
        }
    }
    cout << cnt -1 << "\n";
    for(int i=1;i<p.size();i++){
        cout << p[i].first << " " << p[i].second << "\n";
    }
}
