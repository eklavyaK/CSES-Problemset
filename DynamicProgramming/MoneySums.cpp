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
 
 
const int N = 2e5;
bool dp[2][N];
 
 
void code(int TC){
	int n; cin>>n;
	int c[n], l = 0; dp[1-l][0] = 1;
	for(int i=0;i<n;i++) cin >> c[i];
	for(int j=0;j<n;j++){
		int M = 1000 * (j+1);
		for(int i=0;i<=M;i++){
			if(dp[1-l][i] || (i-c[j]>=0 && dp[1-l][i-c[j]])) dp[l][i] = 1;
		}
		l^=1;
	}
	int k = 0;
	for(int i=1;i<N;i++) if(dp[1-l][i]) k++;
	cout<<k<<endl;
	for(int i=1;i<N;i++) if(dp[1-l][i]) cout<<i<<" ";
}
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}