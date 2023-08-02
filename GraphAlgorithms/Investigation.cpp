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
 
 
const int N = 1e5+5, M = 1e9+7;
vector<pair<int,int>> G[N], R[N];
vector<int> D(N,1e18), MX(N), MN(N,N), V(N), idg(N), P(N);
 
void code(int TC){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,c; cin>>u>>v>>c;
        G[u].push_back({v,c});
        R[v].push_back({u,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,n});
    D[n] = 0;
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(V[u]) continue;
        else V[u] = 1;
        for(auto [v,c] : R[u]){
            if(D[v]>d+c){
                D[v] = d+c;
                pq.push({D[v],v});
            }
        }
    }
    fill(V.begin(),V.end(),0);
    function<void(int)> dfs = [&](int node){
        V[node] = 1;
        for(auto [u,c] : G[node]){
            if(D[u]+c==D[node]) idg[u]++;
            if(D[u]+c==D[node] && !V[u]) dfs(u);
        }
    };
    dfs(1);
    queue<int> q;
    q.push(1);
    MX[1] = MN[1] = 0;
    P[1] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        debug(u,P[u]);
        for(auto [v,c] : G[u]){
            if(D[v]+c==D[u]){
                P[v] = (P[v] + P[u]) % M;
                MX[v] = max(MX[u]+1,MX[v]);
                MN[v] = min(MN[u]+1,MN[v]);
                idg[v]--;
                if(!idg[v]) q.push(v);
            }
        } 
    }
    cout<<D[1]<<" "<<P[n]<<" "<<MN[n]<<" "<<MX[n]<<endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}