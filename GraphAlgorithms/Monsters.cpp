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
vector<char> p{'D','L','R','U'};
 
void code(int TC){
    int n,m; cin>>n>>m;
    vector<string> v(n);
    pair<int,int> loc;
    for(int i=0;i<n;i++) cin>>v[i];
    vector<pair<int,int>> exits, mons, me;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1 && v[i][j]!='#') exits.push_back({i,j});
            if(v[i][j]=='M') mons.push_back({i,j});
            if(v[i][j]=='A') me.push_back({i,j});
        }
    }
    queue<pair<int,int>> q;
    vector<vector<int>> A(n,vector<int>(m,1e9));
    vector<vector<int>> M(n,vector<int>(m,1e9));
    A[me[0].F][me[0].S] = 0;
    q.push({me[0].F,me[0].S});
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        for(auto [dx,dy] : r){
            if(i+dx<n && j+dy<m && i+dx>=0 && j+dy>=0 && v[i+dx][j+dy]!='#' && A[i+dx][j+dy]>A[i][j]+1){
                A[i+dx][j+dy] = A[i][j]+1;
                q.push({i+dx,j+dy});
            }
        }
    }
    for(auto [i,j] : mons) q.push({i,j}), M[i][j] = 0;
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        for(auto [dx,dy] : r){
            if(i+dx<n && j+dy<m && i+dx>=0 && j+dy>=0 && v[i+dx][j+dy]!='#' && M[i+dx][j+dy]>M[i][j]+1){
                M[i+dx][j+dy] = M[i][j]+1;
                q.push({i+dx,j+dy});
            }
        }
    }
    vector<char> route;
    function<void(int,int)> dfs = [&](int i, int j){
        if(v[i][j]=='A') return;
        for(int k=0;k<4;k++){
            auto [dx,dy] = r[k];
            if(i+dx<n && j+dy<m && i+dx>=0 && j+dy>=0 && v[i+dx][j+dy]!='#' && A[i+dx][j+dy]==A[i][j]-1){
                route.push_back(p[k]);
                dfs(i+dx,j+dy);
                return;
            }
        }
    };
    for(auto [i,j] : exits){
        if(M[i][j]>A[i][j]){
            cout<<"YES\n"<<A[i][j]<<endl;
            dfs(i,j);
            reverse(route.begin(),route.end());
            for(auto i : route) cout<<i;cout<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}