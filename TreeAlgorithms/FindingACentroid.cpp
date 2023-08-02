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
 
 
const int N = 2e5 + 5;
vector<vector<int>> T(N);
int sz[N];

void dfs(int u, int p){
     sz[u] = 1;
     for(auto v : T[u]) if(v != p) dfs(v, u), sz[u] += sz[v];
}
int centroid(){
     dfs(1, 0);
     int ctr = 1, p = 0;
     while(int found = 1){
          for(auto v : T[ctr]){
               if(v == p || 2 * sz[v] <= sz[1]) continue;
               p = ctr, ctr = v, found = 0; break;
          }
          if(found) break;
     }
     return ctr;
}
 
void code(int TC){
     int n; cin >> n;
     for(int i = 1; i < n; i++){
          int u, v; cin >> u >> v;
          T[u].push_back(v);
          T[v].push_back(u);
     }
     cout << centroid();
}
 
 
signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}