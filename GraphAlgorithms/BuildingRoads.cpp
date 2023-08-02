#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a,n) 42
#define debug(...) 42
#endif
 
 
 
 
 
void code(int TC){
    int n,m; cin>>n>>m;
    int vis[n+1]{};
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    function<void(int)> dfs = [&](int node){
        vis[node] = 1;
        for(auto i : graph[node]){
            if(!vis[i]) dfs(i);
        }
    };
    int ans = -1;
    vector<int> roads;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans++;
            dfs(i);
            roads.push_back(i);
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<roads.size();i++){
        cout<<roads[i]<<" "<<roads[i-1]<<endl;
    }
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}