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
int Seg[2 * N], pos[N][2], c[N], id, n, q;
vector<vector<int>> T(N);
 
void upd(int pos, int c){
     for(Seg[pos += n] = c; pos >>= 1;) Seg[pos] = Seg[2 * pos] + Seg[2 * pos + 1];
}
int qry(int l, int r){
     if(r < l) return 0;
     int res = 0;
     for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
          if(l & 1) res += Seg[l++];
          if(r & 1) res += Seg[--r];
     }
     return res;
}
 
void code(int TC){
     cin >> n >> q;
     for (int i = 1; i <= n; i++) cin >> c[i];
     for (int i = 1; i < n; i++){
          int u, v; cin >> u >> v;
          T[u].push_back(v);
          T[v].push_back(u);
     }
     memset(pos, -1, sizeof(pos));
     function<void(int, int)> dfs = [&](int u, int p){
          pos[u][0] = id++;
          upd(id - 1, c[u]);
          for (auto v : T[u]) if (v != p) dfs(v, u);
          pos[u][1] = id - 1;
     };
     dfs(1, 0);
     while(q--){
          int qrt; cin >> qrt;
          if(qrt == 1){
               int u, val; cin >> u >> val;
               upd(pos[u][0], val);
          }
          else{
               int u; cin >> u;
               cout << qry(pos[u][0], pos[u][1]) << endl;
          }
     }
}
 
signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for (int TC = 1; TC <= TT; TC++)
          code(TC);
     return 0;
}