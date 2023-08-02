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
 
const int M = 1e9+7, N = 1e6+7;
int dp[N], C[105];
 
 
void code(int TC){
    int n,x; cin>>n>>x;
    for(int i=0;i<n;i++) cin>>C[i];
    for(int i=1;i<=x;i++) dp[i] = 1e9;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++) if(i-C[j]>=0) dp[i] = min(dp[i],dp[i-C[j]]+1);
    }
    cout<<(dp[x]==1e9?-1:dp[x])<<endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}