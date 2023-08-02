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
 
 
const int N = 2e5+5;
int a[N];
void code(int TC){
	int n; cin>>n;
     for(int i=0;i<n;i++) cin>>a[i];
     vector<int> inc;
     for(int i=0;i<n;i++){
          int id = lower_bound(inc.begin(),inc.end(),a[i])-inc.begin();
          if(id == inc.size()) inc.push_back(a[i]);
          else inc[id] = a[i];
     }
     cout<< (int)inc.size();
}
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}