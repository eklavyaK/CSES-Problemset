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

const int N = 1e5+5;
vector<vector<int>> graph(N);
int vis[N], proc[N], mn[N], n, m, id = 0, cnt = 1;
vector<int> ans[N];
bool inStack[N];
stack<int> comps;
void dfs(int node){
    vis[node] = 1;
    comps.push(node);
    inStack[node]=true;
    proc[node]=mn[node]=++id;
    for(auto i : graph[node]){
        if(!vis[i]) dfs(i);
        if(inStack[i]) mn[node] = min(mn[i],mn[node]);
    }
    if(mn[node]!=proc[node])return;
    while(true){
        int c = comps.top();
        mn[c] = proc[node];
        inStack[c] = false;
        comps.pop();
        ans[cnt].push_back(c);
        if(c==node)break;
    }
    cnt++;
}
void SCC(){
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
}
bool travs[N];
ll tot[N],mx[N];
int coin[N], scc[N];
vector<int> comp[N];
void dfs_scc(int node){
    travs[node]=1;
    mx[node]=tot[node];
    for(auto i : comp[node]){
        if(!travs[i]){
            dfs_scc(i);
        }
        mx[node]=max(mx[node],mx[i]+tot[node]);
    }
}
int main(){
    rapid_iostream;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>coin[i];
    }
    while(m--){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }
    SCC();
    for(int i=1;i<=n;i++){
        for(auto u : ans[i]){
            scc[u]=i;
        }
    }
    for(int i=1;i<=n;i++){
        tot[scc[i]]+=coin[i];
    }
    for(int i=1;i<=n;i++){
        for(auto u : graph[i]){
            if(scc[u]!=scc[i])
            comp[scc[i]].push_back(scc[u]);
        }
    }
    for(int i=1;i<cnt;i++){
        if(!travs[i])dfs_scc(i);
    }
    cout<<*max_element(mx,mx+cnt);
    return 0;
}