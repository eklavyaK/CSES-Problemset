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
int dp[N][2];
void calc(){
    dp[0][1] = dp[0][0] = 1;
    for(int i=1;i<N;i++){
        dp[i][0] = (dp[i-1][0] * 4 + dp[i-1][1]) % M;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 2) % M;
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    calc(); int TC, TT; cin>>TT;
    while(TT--) cin >> TC, cout << (dp[TC-1][0] + dp[TC-1][1]) % M << endl;
    return 0;
}