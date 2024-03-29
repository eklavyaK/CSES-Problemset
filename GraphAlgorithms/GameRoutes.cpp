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
vector<int> G[N];
vector<int> D(N), P(N), idg(N), V(N);
 
void code(int TC){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
    }
    function<void(int)> dfs = [&](int node){
        V[node] = 1;
        for(auto i : G[node]){
            if(!V[i]) dfs(i);
            idg[i]++;
        }
    };
    dfs(1);
    queue<int> q;
    q.push(1);
    D[1] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : G[u]){
            D[v] = (D[v] + D[u]) % M;
            idg[v]--;
            if(!idg[v]) q.push(v);
        }
    }
    cout<<D[n]<<endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}