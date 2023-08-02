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
 
const int N = 1e6+7;
int dp[N];
 
 
void code(int TC){
    const int M = 1e9+7;
    dp[0] = 1;
    int n; cin>>n;
 
    for(int i=0;i<=n;i++){
        if((dp[i]>>62) > 0) dp[i] %= M;
        for(int j=1;j<=6;j++) dp[i+j] = dp[i+j] + dp[i];  
    }
    cout<<dp[n] % M;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}