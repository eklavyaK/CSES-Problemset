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
    int n,m; cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    function<void(int,int)> dfs = [&](int i, int j){
        v[i][j] = '#';
        if(i-1>=0 && v[i-1][j]=='.') dfs(i-1,j);
        if(j-1>=0 && v[i][j-1]=='.') dfs(i,j-1);
        if(i+1<n && v[i+1][j]=='.') dfs(i+1,j);
        if(j+1<m && v[i][j+1]=='.') dfs(i,j+1);
    };
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='.') cnt++, dfs(i,j);
        }
    }
    cout<<cnt<<endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}