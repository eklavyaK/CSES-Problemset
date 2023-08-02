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
    vector<vector<pair<int,int>>> G(n+5);
    vector<int> idg(n+5), E(m), vis(n+5);
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        idg[u]++, idg[v]++;
        G[u].push_back({v,j});
    }
    bool f = false;
    if(idg[1] % 2 == 0 || idg[n] % 2 == 0) f = true;
    for(int i=2;i<n;i++){
        if(idg[i] & 1) f = true;
    }
    if(f){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<queue<int>> C(n+5);
    function<void(int,int)> dfs = [&](int u, int node){
        vis[u] = 1;
        C[node].push(u);
        while(!G[u].empty()){
            auto [v,e] = G[u].back();
            G[u].pop_back();
            if(!E[e]){
                E[e] = 1, dfs(v,node);
                return;
            }
        }
    };
    dfs(1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]) continue;
        while(!G[i].empty()){
            auto [v,e] = G[i].back();
            if(!E[e]) dfs(i,i), debug(i,C[i]);
            else G[i].pop_back();
        }
    }
    for(int i=0;i<m;i++){
        if(!E[i]){
            debug(i);
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    function<void(int)> construct = [&](int u){
        while(!C[u].empty()){
            int node = C[u].front(); C[u].pop();
            if(u!=node && !C[node].empty()) construct(node);
            else cout<<node<<" ";
        }
    };
    construct(0);
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}