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
 
 
const int N = 5e3 + 5;
int dp[N][N];
 
 
void code(int TC){
    string I, T; cin>>I>>T;
    int n = I.size(), m = T.size();
    for(int i=1;i<=m;i++) dp[0][i] = i;
    for(int i=1;i<=n;i++) dp[i][0] = i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(I[i-1]==T[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) + 1;
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