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
	vector<int> dp(n);
	vector<tuple<int,int,int>> range(n);
	for(int i=0;i<n;i++){
		int l, r, c;
		cin>>l>>r>>c;
		range[i] = {r,l,c};
	}
	sort(range.begin(),range.end());
	for(int i=0;i<n;i++){
		auto [r,l,c] = range[i];
		int id = lower_bound(range.begin(), range.end(), tuple<int,int,int>{l,0,0}) - range.begin();
		dp[i] = max(c,dp[i-1*(i!=0)]);
		if(id-1>=0) dp[i] = max(dp[i], dp[id-1]+c);
	}
	cout<<dp[n-1];
}
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}
