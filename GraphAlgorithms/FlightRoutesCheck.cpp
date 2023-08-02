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
 
const int N = 1e5+5;
vector<int> G[2][N];
int V[2][N];
 
void code(int TC){
    int n,m; cin>>n>>m;
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        G[0][u].push_back(v);
        G[1][v].push_back(u);
    }
    function<void(int,int)> dfs = [&](int id, int u){
        V[id][u] = 1;
        for(auto v : G[id][u]) if(!V[id][v]) dfs(id, v);
    };
    dfs(0,1);
    dfs(1,1);
    for(int i=1;i<=n;i++){
        if(!V[0][i] || !V[1][i]){
            cout<<"NO\n";
            !V[0][i]?cout<<1<<" "<<i:cout<<i<<" "<<1;
            return;
        }
    }
    cout<<"YES";
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}