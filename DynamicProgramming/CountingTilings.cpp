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
 
const int M = 1e9 + 7;
 
int add(int A){
	if(A>=M) A-=M;
	return A;
}
 
void code(int TC){
	int n,m; cin>>n>>m;
	vector<int> E;
	for(int i=0;i<(1<<n);i++){
		bool f = true;
		for(int j=0;j<n;j++){
			if(!((1<<j)&i)) continue;
			int c = j;
			while(j+1<n && ((1<<(j+1))&i)) j++;
			if((j-c+1)&1) f = false;
		}
		if(f) E.push_back(i);
	}
	int dp[m][1<<n], cap = (1<<n)-1;
	memset(dp,0,sizeof(dp));
	for(auto i : E) dp[0][i] = 1;
	for(int j=1;j<m;j++){
		for(int i=0;i<=cap;i++){
			for(auto e : E) if(!(e&(i^cap))) dp[j][e|(i^cap)] = add(dp[j][e|(i^cap)] + dp[j-1][i]);
		}
	}
	cout<<dp[m-1][cap];
}
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}