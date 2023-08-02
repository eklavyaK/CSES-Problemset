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
 
int exp(int a, int n){
	int res = 1;
	while(n>0){
		if(n&1) res = (a*res);
		a = (a*a), n>>=1;
	}
	return res;
}
int down(vector<int> a, int n){
	int ans = max(0ll, (a[0] - 1) * exp(9, n - 1)), f = 1;
	for(int i=1;i<n;i++) ans += max(0ll, f * (a[i] - (a[i-1] < a[i])) * exp(9, n - i - 1)), f = f && (i==0 || i>0 && a[i] != a[i-1]);
	return ans + (n==1);
}
int up(vector<int> a, int n){
	int ans = max(0ll, (9 - a[0]) * exp(9, n - 1)), f = 1;
	for(int i=1;i<n;i++) ans += max(0ll, f * (9 - a[i] - (a[i-1] > a[i])) * exp(9, n - i - 1)), f = f && (i==0 || i>0 && a[i] != a[i-1]);
	return ans;
}
int all(int n){
	return exp(9, n) + (n==1);
}
void code(int TC){
	string A,B; cin>>A>>B;
	int n = A.size(), m = B.size(), a = 1, b = 1;
	vector<int> an(n), bn(m);
	for(int i=0;i<n;i++) an[i] = (A[i] - 48), a = a && (i==0 || i>0 && A[i] != A[i-1]);
	for(int i=0;i<m;i++) bn[i] = (B[i] - 48), b = b && (i==0 || i>0 && B[i] != B[i-1]);
	int ans = 0, u = up(an, n), v = down(bn, m);
	for(int i=n+1;i<m;i++) ans += all(i);
	debug(a,b,u,v, ans);
	if(A == B) cout<< a;
	else cout << a + b + ((n == m) ? u + v - all(n) : u + v + ans);
}
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}