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
 
 
const int N = 505;
int dp[N][N];
 
 
void code(int TC){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j) continue;
            dp[i][j] = 1e9;
            for(int k=1;k<=min(i,j);k++){
                if(k==i) dp[i][j] = min(dp[i][j], dp[k][j-k] + 1);
                else if(k==j) dp[i][j] = min(dp[i][j], dp[i-k][k] + 1);
                else dp[i][j] = min({dp[i][j], dp[i][j-k] + dp[i-k][k] + 2, dp[i-k][j] + dp[k][j-k] + 2});
            }
        }
    }
    cout<<dp[n][m];
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}