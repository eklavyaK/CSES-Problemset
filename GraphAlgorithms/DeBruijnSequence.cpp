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
 
 
 
 
 
void code(int TC){
    int n; cin>>n;
    int m = 1<<n;
    int vis[m]{1};
    vector<bool> ans;
    for(int i=0;i<n;i++) ans.push_back(0);
    int cur = 0, e = 1<<n, l = n;
    while(true){
        if(!vis[(cur<<1) + 1 - e*ans[l-n]]) cur = (cur<<1) + 1 - e*ans[l-n], vis[cur] = 1, ans.push_back(1);
        else if(!vis[(cur<<1) - e*ans[l-n]]) cur = (cur<<1) - e*ans[l-n], vis[cur] = 1, ans.push_back(0);
        else break;
        l = l+1;
    }
    for(auto i : ans) cout<<i;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}