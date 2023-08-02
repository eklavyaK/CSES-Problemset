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
	int n,x; cin>>n>>x;
	vector<int> c(n);
	for(int i=0;i<n;i++) cin>>c[i];
	vector<vector<int>> dp(1<<n,{25,(int)1e18});
	dp[0] = {1,0};
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((1<<j)&i) continue;
			auto [l,r] = dp[i][1] + c[j] > x ? make_pair(dp[i][0] + 1, c[j]) : make_pair(dp[i][0], dp[i][1] + c[j]);
			if(dp[i^(1<<j)][0] > l || (dp[i^(1<<j)][0] == l && dp[i^(1<<j)][1] > r)) dp[i^(1<<j)] = {l, r};
		}
		debug(i,dp[i][0]);
	}
	cout<<dp[(1<<n)-1][0];
}
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}