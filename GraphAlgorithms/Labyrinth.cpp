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
 
 
 
vector<pair<int,int>> r{{-1,0},{0,1},{0,-1},{1,0}};
vector<char> p{'U','R','L','D'};
 
void code(int TC){
    int n,m; cin>>n>>m;
    vector<string> v(n);
    pair<int,int> loc;
    for(int i=0;i<n;i++){
        cin>>v[i];
        for(int j=0;j<m;j++) if(v[i][j]=='B') loc = {i,j};
    }
    queue<pair<int,int>> q;
    vector<vector<int>> d(n,vector<int>(m,1e9));
    d[loc.F][loc.S] = 0;
    q.push(loc);
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        if(v[i][j]=='A') loc = {i,j};
        for(auto [dx,dy] : r){
            if(i+dx<n && j+dy<m && i+dx>=0 && j+dy>=0 && v[i+dx][j+dy]!='#' && d[i+dx][j+dy]>d[i][j]+1){
                d[i+dx][j+dy] = d[i][j]+1;
                q.push({i+dx,j+dy});
            }
        }
    }
    if(d[loc.first][loc.second]==1e9 || !d[loc.first][loc.second]){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES\n"<<d[loc.first][loc.second]<<endl;
    function<void(int,int)> dfs = [&](int i, int j){
        if(v[i][j]=='B') return;
        for(int k=0;k<4;k++){
            auto [dx,dy] = r[k];
            if(i+dx<n && j+dy<m && i+dx>=0 && j+dy>=0 && v[i+dx][j+dy]!='#' && d[i+dx][j+dy]==d[i][j]-1){
                cout<<p[k];
                dfs(i+dx,j+dy);
                return;
            }
        }
    };
    dfs(loc.first,loc.second);
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}