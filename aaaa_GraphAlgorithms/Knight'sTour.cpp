/*
Warnsdorf's Rule is used to solve the Knight's Tour problem in most optimized way.

The idea behind Warnsdorf's Rule is that if knight is standing on a box and has to move to the next unvisited box, then the selection of 
next box is such that it's degree is minimum amongst all possible next boxes. The degree of a box is defined as number of possible moves can
be made from the box to an unvisited box.
*/
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************MAIN PROGRAM*******************************************************/
int cnt = 0;
vector<vector<int>> ans(8,vector<int>(8));
vector<vector<bool>> vis(8,vector<bool>(8));
vector<array<int,2>> L({{-1,-2},{-2,-1},{-1,2},{2,-1},{1,-2},{-2,1},{1,2},{2,1}});
bool check(int u, int v){
    return !(u<0||v<0||u>7||v>7||vis[u][v]);
}
int find_deg(int u, int v){
    int deg = 0;
    for(int i=0;i<8;i++){
        int nu=L[i][0]+u;
        int nv=L[i][1]+v;
        deg+=check(nu,nv);
    }
    return deg;
}
void KnightTour(int u, int v){
    vis[u][v] = 1;
    ans[u][v]=++cnt;
    vector<array<int,2>> next;
    for(int i=0;i<8;i++){
        int nu=L[i][0]+u;
        int nv=L[i][1]+v;
        if(check(nu,nv)){
            next.push_back({find_deg(nu,nv),i});
        }
    }
    sort(next.begin(),next.end());
    for(int i=0;i<next.size();i++){
        KnightTour(L[next[i][1]][0]+u,L[next[i][1]][1]+v);
    }
    if(cnt<64){
        vis[u][v] = 0;
        ans[u][v] = 0;
        --cnt;
    }
    else{
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<ans[i][j]<<' ';
            }
            cout<<endl;
        }
        exit(0);
    }
}
int main(){
    rapid_iostream;
    int u,v; cin>>u>>v; --v;--u;
    KnightTour(v,u);
    return 0;
}