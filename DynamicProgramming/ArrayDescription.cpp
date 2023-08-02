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
int dp[105][N];
int add(int A){
    if(A>=M) A-=M;
    return A;
}
void code(int TC){
    int n,m; cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    if(a[0]==0) for(int i=1;i<=m;i++) dp[i][0] = 1;
    else dp[a[0]][0] = 1;
    for(int i=1;i<n;i++){
        if(a[i]!=0) dp[a[i]][i] = add(add(dp[a[i]-1][i-1] + dp[a[i]+1][i-1]) + dp[a[i]][i-1]);
        else for(int j=1;j<=m;j++) dp[j][i] = add(add(dp[j-1][i-1] + dp[j+1][i-1]) + dp[j][i-1]);
    }
    int ans = 0;
    for(int i=1;i<=m;i++) ans += dp[i][n-1];
    cout<<ans % M<<endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}