#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
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
int sz[N], n, k1, k2;
bool I[N];
vector<int> C, T[N];
 
void dfs (int u, int p){
     sz[u] = 1;
     for(auto v : T[u]) if(!I[v] && v != p) dfs(v, u), sz[u] += sz[v];
}
 
void childinfo(int u, int p, int dep){
     if(C.size() <= dep) C.push_back(1);
     else ++C[dep];
     for(auto v : T[u]) if(!I[v] && v != p) childinfo(v, u, dep+1);
}
 
ll decompose(int u){
     dfs(u, 0);
     int ctr = u, p = 0;
     while(int f = 1){
          for(auto v : T[ctr]) if(!I[v] && 2 * sz[v] > sz[u] && v != p){
               p = ctr, ctr = v, f = 0; break;
          }
          if(f) break;
     }
     I[ctr] = 1;
     vector<int> P(1, 1);
     ll ans = 0;
     for(auto u : T[ctr]){
          if(I[u]) continue;
          ans += decompose(u);
          C.assign(1,0), childinfo(u,ctr,1);
          for(int i = min(k2, (int)C.size() - 1); i >= 0; i--){
               int l = max(0, k1 - i), r = min((int)P.size() - 1, k2 - i);
               if(l > r) continue;
               if(r == (int)P.size() - 1) ans += 1ll *  P[l] * C[i];
               else ans += 1ll * (P[l] - P[r+1]) * C[i];
          }
          for(int i = (int)C.size() - 2; i >= 0; i--) C[i] += C[i+1];
          if(C.size() > P.size()) swap(C, P);
          for(int i = 0; i < (int)C.size(); i++)  P[i] += C[i];
     }
     I[ctr] = 0;
     return ans;
}
 
void code(int TC){
     cin>>n>>k1>>k2;
     for(int i=0;i<n-1;i++){
          int u,v; cin>>u>>v;
          T[u].push_back(v); 
          T[v].push_back(u);
     }
     cout<< decompose(1);
}
 
 
signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}