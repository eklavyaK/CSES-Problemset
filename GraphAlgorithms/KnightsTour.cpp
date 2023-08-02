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
 
 
vector<pair<int,int>> m{{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int I[8][8], U[8][8];
bool check(int i, int j, int dx, int dy){
    return i+dx>=0 && j+dy>=0 && i+dx<8 && j+dy<8;
}
void print(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++) cout<<U[i][j]<<' ';
        cout<<endl;
    }
    exit(0);
}
void code(int TC){
    int x, y; cin>>x>>y; --x, --y;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            for(auto [dx,dy] : m) if(check(i,j,dx,dy)) I[i+dx][j+dy]++;
        }
    }
    function<void(int,int,int)> dfs = [&](int i, int j, int c){
        U[i][j] = c;
        if(c==64) print();
        vector<pair<int,int>> go;
        for(int k=0;k<8;k++){
            auto [dx,dy] = m[k];
            if(check(i,j,dx,dy)){
                I[i+dx][j+dy]--;
                if(!U[i+dx][j+dy]) go.push_back({I[i+dx][j+dy],k});
            }
        }
        sort(go.begin(),go.end());
        for(auto [_,id] : go){
            auto [dx,dy] = m[id];
            dfs(i+dx,j+dy,c+1);
        }
        for(int k=0;k<8;k++){
            auto [dx,dy] = m[k];
            if(check(i,j,dx,dy)) I[i+dx][j+dy]++;
        }
        U[i][j] = 0;
    };
    dfs(y,x,1);
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}