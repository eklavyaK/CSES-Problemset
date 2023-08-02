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
 
const int M = 1e9+7, N = 1e5+7;
int dp[2][N];
 
void code(int TC){
    int n,x; cin>>n>>x;
    int P[n],C[n], l = 0;
    for(int i=0;i<n;i++) cin>>C[i];
    for(int i=0;i<n;i++) cin>>P[i];
    for(int j=0;j<n;j++){
        for(int i=0;i<=x;i++){
            dp[l][i] = dp[1-l][i];
            if(C[j]<=i) dp[l][i] = max(dp[l][i], dp[1-l][i-C[j]] + P[j]);
        }
        l^=1;
    }
    cout<<dp[1-l][x];
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}