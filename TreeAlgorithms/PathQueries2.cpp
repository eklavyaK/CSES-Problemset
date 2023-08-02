#include <bits/stdc++.h>
#define endl "\n"
#define ii first
#define jj second
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
int pos, n;
vector<int> id(N), dep(N), sC(N), bigc(N), up(N), par(N), Seg, c(N);
vector<vector<int>> T;
void dfssz(int u, int p){
     sC[u] = 1;
     for(auto v : T[u]){
          if(v == p) continue;
          par[v] = u, dep[v] = dep[u] + 1;
          dfssz(v, u);
          sC[u] += sC[v];
          bigc[u] = sC[bigc[u]] < sC[v] ? v : bigc[u];
     }
}
void dfsid(int u, int p){
     id[u] = pos++;
     if(bigc[u]) up[bigc[u]] = up[u], dfsid(bigc[u], u);
     for(auto v : T[u]) if(v != p && v != bigc[u]) dfsid(v, u);
}
int lca(int u, int v){
     while(up[u] != up[v]) dep[up[u]] > dep[up[v]] ? u = par[up[u]] : v = par[up[v]];
     return dep[u] < dep[v] ? u : v;
}
void build(int n){
     Seg.assign(2 * n + 5, 0);
     for(int i = 1; i <= n; i++) Seg[id[i] + n] = c[i];
     for(int i = n - 1; i > 0; --i) Seg[i] = max(Seg[i << 1], Seg[i << 1 | 1]);
}
void upd(int pos, int c){
     for(Seg[pos += n] = c; pos >>= 1;) Seg[pos] = max(Seg[2 * pos], Seg[2 * pos + 1]);
}
int qry(int l, int r){
     if(r < l) return 0;
     int mx = 0;
     for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
          if(r & 1) mx = max(mx, Seg[--r]);
          if(l & 1) mx = max(mx, Seg[l++]);
     }
     return mx;
}
void update(int u, int val){
     upd(id[u], val);
}
int query(int u, int v){
     int mx = 0;
     while (up[u] != up[v]){
          if(dep[up[u]] > dep[up[v]]) mx = max(mx, qry(id[up[u]], id[u])), u = par[up[u]];
          else mx = max(mx, qry(id[up[v]], id[v])), v = par[up[v]];
     }
     if(dep[u] > dep[v]) swap(u, v);
     return max(mx, qry(id[u], id[v]));
}
void HLD(vector<vector<int>> Tree, int N){
     for(int i = 0; i <= N; i++) id[i] = dep[i] = sC[i] = bigc[i] = par[i] = 0, up[i] = i;
     dep[0] = -1, n = N, T = Tree;
     dfssz(1, 0), dfsid(1, 0);
     build(n);
}
 
void code(int TC){
     int n, q;
     cin >> n >> q;
     vector<vector<int>> Tree(n + 5); 
     for(int i = 1; i <= n; i++) cin >> c[i];
     for(int i = 1; i < n; i++){
          int u, v;
          cin >> u >> v;
          Tree[u].push_back(v);
          Tree[v].push_back(u);
     }
     HLD(Tree, n);
     for(int i = 1; i <= n; i++) update(i, c[i]);
     while(q--){
          int qrt;
          cin >> qrt;
          if(qrt == 1){
               int u, val;
               cin >> u >> val;
               update(u, val);
 
          }
          else{
               int u, v;
               cin >> u >> v;
               cout << query(u, v) << ' ';
          }
     }
}
 
signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0); cout.tie(0); cerr.tie(0);
     int TT = 1;
     for(int TC = 1; TC <= TT; TC++)
          code(TC);
     return 0;
}