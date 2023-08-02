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
 
 
vector<vector<int>> Tarjan(vector<vector<int>> G, int n){
    vector<vector<int>> C; int id = 0;
    vector<int> s, f(n+5), p(n+5), inStack(n+5), vis(n+5);
    function<void(int)> dfs = [&](int u){
        inStack[u] = vis[u] = 1;
        f[u] = p[u] = id = id+1;
        s.push_back(u);
        for(auto v : G[u]){
            if(!vis[v]) dfs(v);
            if(inStack[v]) f[u] = min(f[u],f[v]);
        }
        if(f[u]!=p[u]) return;
        vector<int> cur;
        while(s.back()!=u) cur.push_back(s.back()), inStack[s.back()] = 0, s.pop_back();
        cur.push_back(u), inStack[u] = 0, s.pop_back(), C.push_back(cur);
    };
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    return C;
}
 
void code(int TC){
    int n, m; cin>>n>>m;
    vector<vector<int>> G(n+5), R(n+5);
    vector<int> coin(n+5), comp(n+5), tot(n+5), idg(n+5), dp(n+5);
    for(int i=1;i<=n;i++) cin>>coin[i];
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
    }
    auto C = Tarjan(G,n);
    for(int i=0;i<C.size();i++){
        for(auto j : C[i]) comp[j] = i+1, tot[i+1] += coin[j];
    }
    for(int i=1;i<=n;i++){
        for(auto u : G[i]) if(comp[u]!=comp[i]) R[comp[i]].push_back(comp[u]), idg[comp[u]]++;
    }
    n = C.size();
    queue<int> q;
    for(int i=1;i<=n;i++) if(!idg[i]) q.push(i), dp[i] = tot[i];
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto i : R[u]){
            dp[i] = max(dp[i],dp[u]+tot[i]);
            idg[i]--;
            if(!idg[i]) q.push(i);
        }
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}