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
 
const int M = 1e9+7;
int dp[20][1<<20];
vector<int> E[20];
int add(int A){
    if(A>=M) A-=M;
    return A;
}
void code(int TC){
    int n,m; cin>>n>>m;
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v; u--, v--;
        E[v].push_back(u);
    }
    dp[0][1] = 1;
    for(int i=3;i<(1<<n);i+=2){
        for(int v=1;v<n;v++) if((1<<v)&i){
            for(auto u : E[v]) dp[v][i] = add(dp[v][i] + dp[u][i^(1<<v)]);
        }
    }
    cout<<dp[n-1][(1<<n)-1];
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}