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
 
 
 
const int N = 2e5+5;
vector<int> D(N,1e18), U(N,1e18), V(N);
vector<pair<int,int>> G[N],R[N];
 
void code(int TC){
    int n,m; cin>>n>>m;
    while(m--){
        int u,v,c; cin>>u>>v>>c;
        G[u].push_back({v,c});
        R[v].push_back({u,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    D[n] = 0;
    q.push({0,n});
    while(!q.empty()){
        auto [d,u] = q.top(); q.pop();
        if(V[u]) continue;
        else V[u] = 1;
        for(auto [v,c] : R[u]){
            if(D[v]>D[u]+c){
                D[v] = D[u] + c;
                q.push({D[v],v});
            }
        }
    }
    U[1] = 0;
    q.push({0,1});
    fill(V.begin(),V.end(),0);
    while(!q.empty()){
        auto [d,u] = q.top(); q.pop();
        if(V[u]) continue;
        else V[u] = 1;
        for(auto [v,c] : G[u]){
            if(U[v]>U[u]+c){
                U[v] = U[u] + c;
                q.push({U[v],v});
            }
        }
    }
    int ans = 1e18;
    for(int u=1;u<=n;u++){
        for(auto [v,c] : G[u]){
            ans = min(ans, U[u]+D[v]+c/2);
        }
    }
    cout<<ans<<endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}