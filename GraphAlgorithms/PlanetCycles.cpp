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
int p[N][35], cyc[N], vis[N], dep[N], ckl[N];
 
void code(int TC){
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i][0];
    for(int i=1;i<35;i++){
        for(int j=1;j<=n;j++) p[j][i] = p[p[j][i-1]][i-1];
    }
    int c = 1;
    for(int i=1;i<=n;i++){
        if(vis[p[i][25]]) continue;
        int cur = p[i][25];
        int sz = 0;
        while(!vis[cur]) sz += 1, vis[cur] = sz, cur = p[cur][0], cyc[cur] = c;
        ckl[c++] = sz;
    }
    function<int(int)> calc = [&](int cur){
        if(cyc[cur]) return 0ll;
        if(dep[cur]) return dep[cur];
        return dep[cur] = calc(p[cur][0]) + 1;
    };
    for(int i=1;i<=n;i++) if(!dep[i]) dep[i] = calc(i);
    for(int i=1;i<=n;i++) cout<<dep[i]+ckl[cyc[p[i][25]]]<<" ";cout<<endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}