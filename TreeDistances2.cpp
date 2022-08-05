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



int main(){
    rapid_iostream;
    int n; cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int par[n+1]{},indeg[n+1]{};
    function<void(int)> dfs = [&](int node){
        for(auto i:tree[node]){
            if(i!=par[node]){
                par[i] = node;
                indeg[node]++;
                dfs(i);
            }
        }
    };
    dfs(1);
    ll ans[n+1]{};
    int cnt[n+1]{};
    ll now[n+1]{};
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indeg[i])q.push(i);
    }
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(node==1)break;
        indeg[par[node]]--;
        cnt[par[node]]+=(1+cnt[node]);
        now[par[node]]+=(1+cnt[node]+now[node]);
        if(!indeg[par[node]])q.push(par[node]);
    }
    queue<int> bfs;
    bfs.push(1);
    ans[1] = now[1];
    while(!bfs.empty()){
        int node = bfs.front(); bfs.pop();
        for(auto i : tree[node]){
            if(i!=par[node]){
                ll k = ans[node]-(1+cnt[i]+now[i]);
                ans[i] = k+(n-cnt[i]-1)+now[i];
                bfs.push(i);
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    return 0;
}