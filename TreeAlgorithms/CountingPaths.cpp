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
    int n,m; cin>>n>>m;
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int par[n+1][22],dep[n+1]{}, indeg[n+1]{};
    memset(par,0,sizeof(par));
    function<void(int)> dfs = [&](int node){
        for(auto i : tree[node]){
            if(i!=par[node][0]){
                par[i][0] = node;
                indeg[node]++;
                dep[i] = dep[node]+1;
                dfs(i);
            }
        }
    };
    dfs(1);
    for(int i=1;i<22;i++){
        for(int j=1;j<=n;j++){
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    function<int(int,int)> lca = [&](int u,int v){
        if(dep[u]<dep[v])swap(u,v);
        int k = dep[u]-dep[v];
        for(int i=0;i<22;i++){
            if(k&(1<<i))u = par[u][i];
        }
        if(u==v) return u;
        for(int i=21;i>=0;i--){
            if(par[u][i]!=par[v][i]){
                u = par[u][i];
                v = par[v][i];
            }
        }
        return par[u][0];
    };
    queue<int> bfs;
    for(int i=1;i<=n;i++){
        if(!indeg[i])bfs.push(i);
    }
    int nLca[n+1]{}, cnt[n+1]{};
    while(m--){
        int u,v; cin>>u>>v;
        int node = lca(u,v);
        cnt[u]++;cnt[v]++;
        nLca[node]++;
    }
    int ans[n+1]{};
    while(!bfs.empty()){
        int node = bfs.front(); bfs.pop();
        int next = par[node][0];
        indeg[next]--;
        ans[node]+=cnt[node];
        ans[node]-=nLca[node];
        ans[next]+=(ans[node]-nLca[node]);
        if(!indeg[next])bfs.push(next);
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    return 0;
}