#include<bits/stdc++.h>
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
#define debugarr(a,n) 42
#define debug(...) 42
#endif
 
 
const int N = 2e5 + 5;
vector<int> T[N];
int I[N], V[N], P[N];
 
 
 
void code(int TC){
     int n, M = 0; cin >> n;
     for(int i = 1; i < n; i++){
          int u, v; cin >> u >> v;
          T[u].push_back(v);
          T[v].push_back(u);
          I[u]++, I[v]++;
     }
     queue<int> q;
     for(int i = 2; i <= n; i++) if(I[i] == 1) q.push(i);
     while(!q.empty()){
          int u = q.front(); q.pop();
          for(auto v : T[u]){
               if(!P[v]){
                    P[u] = v;
                    break;
               }
          }
          if(!V[u] && !V[P[u]]) V[u] = V[P[u]] = 1, M = M + 1;
          I[P[u]]--;
          if(P[u] != 1 && I[P[u]] == 1) q.push(P[u]); 
     }
     cout << M;
}
 
 
signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}