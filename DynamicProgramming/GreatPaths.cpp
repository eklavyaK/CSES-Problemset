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
 
const int M = 1e9+7, N = 1e3+7;
int dp[N][N];
 
int add(int A){
    if(A>=M) A-=M;
    return A;
}
void code(int TC){
    int n; cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    if(s[0][0]=='*'){
        cout<<0<<endl;
        return;
    }
    else dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='*') continue;
            if(j>0) dp[i][j] = dp[i][j-1];
            if(i>0) dp[i][j] = add(dp[i-1][j]+dp[i][j]);
        }
    }
    cout<<dp[n-1][n-1];
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for(int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}