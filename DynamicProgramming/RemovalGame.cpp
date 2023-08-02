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
 
 
const int N = 5e3+5;
int dp[N][N], I[N][N];
 
 
void code(int TC){
	int n; cin>>n;
	vector<int> a(n), sum(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) sum[i] = sum[i-1*(i!=0)] + a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j>=0;j--){
			if(i==j) dp[i][j] = a[i];
			else dp[j][i] = a[j] + max(sum[i] - sum[j] - dp[j+1][i], sum[i-1] - sum[j] + a[i] - dp[j][i-1]);
		}
	};
	cout<<dp[0][n-1]<<endl;
}
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}