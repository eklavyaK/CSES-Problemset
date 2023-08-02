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
    vector<vector<int>> graph(n+1);
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> vis(n+1);
    vector<int> route;
    int f = 0;
    function<void(int,int)> dfs = [&](int node, int par){
        vis[node] = 1;
        for(auto i : graph[node]){
            if(i==par) continue;
            if(vis[i]){
                f = i;
                route.push_back(i);
                route.push_back(node);
                return;
            }
            dfs(i,node);
            if(f){
                if(f==-1) return;
                route.push_back(node);
                if(node==f) f = -1;
                return;
            }
        }
    };
    for(int i=1;i<=n;i++) if(!vis[i] && !f) dfs(i,0);
    if(!f){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<route.size()<<endl;
    for(auto i : route) cout<<i<<" ";cout<<endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}