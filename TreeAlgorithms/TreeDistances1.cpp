#include <bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
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
vector<vector<pair<int,int>>> M(N, vector<pair<int,int>>(2));
vector<vector<int>> T(N);
 
void dfs(int u, int p){
     for(auto v : T[u]){
          if(v == p) continue;
          dfs(v, u);
          if(M[v][1].ff + 1 > M[u][0].ff) M[u][0].ff = M[v][1].ff + 1, M[u][0].ss = v;
          sort(M[u].begin(), M[u].end());
     }
}
void calc(int u, int p){
     for(auto v : T[u]){
          if(v == p) continue;
          for(int i = 1; i >= 0; i--){
               if(M[u][i].ss != v && M[u][i].ff + 1 > M[v][0].ff){
                    M[v][0].ff = M[u][i].ff + 1, M[v][0].ss = u;
                    sort(M[v].begin(), M[v].end());
               }
          }
          calc(v, u);
     }
}
void code(int TC){
     int n; cin >> n;
     for (int i = 1; i < n; i++){
          int u, v; cin >> u >> v;
          T[u].push_back(v);
          T[v].push_back(u);
     }
     dfs(1, 0);
     calc(1, 0);
     for(int i = 1; i <= n; i++) cout<< M[i][1].ff << " ";
}
 
signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for(int TC = 1; TC <= TT; TC++)
          code(TC);
     return 0;
}