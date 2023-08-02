#include <bits/stdc++.h>
#define endl "\n"
#define ii first
#define jj second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a, n) 42
#define debug(...) 42
#endif
 
const int N = 2e5 + 5;
vector<vector<int>> T(N);
int sz[N], C[N], P[N], n;
 
void dfs(int u, int p){
     sz[u] = 1;
     for(auto v : T[u]) if(v != p) dfs(v, u), sz[u] += sz[v], C[u] += C[v] + sz[v];
}
void calc(int u, int p){
     for(auto v : T[u]) if(v != p) P[v] = P[u] + C[u] - C[v] + n - 2 * sz[v], calc(v, u);
}
void code(int TC){
     cin >> n;
     for (int i = 1; i < n; i++){
          int u, v; cin >> u >> v;
          T[u].push_back(v);
          T[v].push_back(u);
     }
     dfs(1, 0);
     calc(1, 0);
     for(int i = 1; i <= n; i++) cout<< P[i] + C[i] << " ";
}
 
signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for(int TC = 1; TC <= TT; TC++)
          code(TC);
     return 0;
}