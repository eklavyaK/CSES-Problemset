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
 
 
ll dinic(vector<vector<pair<ll,ll>>> T, ll n, ll src, ll snk, ll C){
    if(src > n || snk > n || src <=0 || snk <= 0) return 0ll;
    vector<vector<bool>> I(n+5,vector<bool>(n+5));
    vector<vector<ll>> p(n+5,vector<ll>(n+5,-1));
    vector<vector<pair<ll,ll>>> G(n+5);
    vector<ll> L(n+5), id(n+5);
    for(ll u=1;u<=n;u++){
        for(ll j=0;j<(ll)T[u].size();j++){
            auto [v,cap] = T[u][j];
            if(p[u][v] == -1) p[u][v] = (ll) G[u].size(), p[v][u] = (ll) G[v].size(), G[u].push_back({v,0}), G[v].push_back({u,0});
            G[u][p[u][v]].second = cap, I[u][v] = G[u][p[u][v]].second > 0;
        }
    }
    auto bfs = [&](){
        L.assign(n+5,-1), L[src] = 0;
        queue<ll> q; q.push(src);
        while(!q.empty()){
            ll u = q.front(); q.pop();
            for(auto [v,c] : G[u]) if(c > 0 && L[v] == -1) L[v] = L[u] + 1, q.push(v);
        }
        return L[snk] != -1;
    };
    function<ll(ll,ll)> dfs = [&](ll u, ll pushed){
        if(u == snk) return pushed;
        for(;id[u] < (ll) G[u].size();id[u]++){
            auto [v, c] = G[u][id[u]];
            if(L[v] != L[u] + 1 || c <= 0) continue;
            if(ll flo = dfs(v, min(pushed, c))){
                G[u][id[u]].second -= flo, G[v][p[v][u]].second += flo;
                return flo;
            }
        }
        return 0ll;
    };
    ll maxflo = 0;
    if(snk == src) return -1ll;
    while(bfs()) id.assign(n+5,0), maxflo += dfs(src,8e18);
    
    // id.assign(n+5,0);
    // vector<pair<int,int>> edges;               //Getting min cut edges
    // function<void(int)> add = [&](int u){
    //     id[u] = 1;
    //     for(auto [v,c] : G[u]) if(!id[v] && c>0) add(v);
    // };
    // add(src);
    // for(int u=1;u<=n;u++) if(id[u]) for(auto [v,c] : G[u]) if(!id[v] && I[u][v]) edges.push_back({u,v});
 
    vector<pair<int,int>> edges;               //Getting min cut edges
    for(int i=1;i<=C;i++){
        for(auto [v,c] : G[i]) if(c<=0 && v<src) edges.push_back({i,v-C});
    }
    
    cout<<maxflo<<endl;
    for(auto [u,v] : edges) cout<<u<<' '<<v<<endl;
    
    return maxflo;
}
 
void code(int TC){
    int n,m,k; cin>>n>>m>>k;
    vector<vector<pair<int,int>>> G(n+m+5);
    for(int i=0;i<k;i++){
        int u,v; cin>>u>>v;
        G[u].push_back({n+v,1});
    }
    for(int i=1;i<=n;i++) G[n+m+1].push_back({i,1});
    for(int j=1;j<=m;j++) G[j+n].push_back({n+m+2,1});
    dinic(G,n+m+2,n+m+1,n+m+2,n);
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}