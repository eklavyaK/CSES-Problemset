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
 
 
const int N = 7e4, M = 1e9+7;
int dp[2][N], l = 0;
int exp(int a, int n){
	int res = 1;
	while(n>0){
		if(n&1) res = (res*a) % M;
		a = (a*a) % M, n>>=1;
	}
	return res;
}
int add(int A){
	if(A>=M) A-=M;
	return A;
}
void code(int TC){
	int n; cin>>n;
	int T = n*(n+1)/2;
	if(T&1){
		cout<<0<<endl;
		return;
	}
	else T>>=1, dp[1-l][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=T;j++){
			dp[l][j] = dp[1-l][j];
			if(j-i>=0) dp[l][j] = add(dp[l][j] + dp[1-l][j-i]);
		}
		l^=1;
	}
	cout<<dp[1-l][T] * exp(2,M-2) % M;
}
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}