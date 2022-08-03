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
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int indeg[n+1]{}, par[n+1]{};
    function<void(int)> dfs = [&](int node){
        for(auto i : tree[node]){
            if(par[node]!=i){
                par[i] = node;
                indeg[node]++;
                dfs(i);
            }
        }
    };
    dfs(1);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indeg[i])q.push(i);
    }
    int dist[n+1]{};
    vector<set<pair<int,int>>> all(n+1);
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(node==1)break;
        all[par[node]].insert({dist[node]+1,node});
        dist[par[node]] = max(dist[par[node]],dist[node]+1);
        indeg[par[node]]--;
        if(!indeg[par[node]])q.push(par[node]);
    }
    while(!q.empty())q.pop();
    queue<pair<int,int>> bfs;
    bfs.push({1,1});
    while(!bfs.empty()){
        auto [node,dis] = bfs.front(); bfs.pop();
        for(auto i : tree[node]){
            if(i!=par[node]){
                auto it = all[node].end();
                it--;
                if(it->second==i){
                    if(all[node].size()==1){
                        dist[i] = max(dist[i],dis);
                        all[i].insert({dis,node});
                    }
                    else{
                        it--;
                        dist[i] = max(dist[i],max(dis,it->first+1));
                        all[i].insert({max(dis,it->first+1),node});
                    }
                }
                else{
                    dist[i] = max(dist[i],max(it->first+1,dis));
                    all[i].insert({max(it->first+1,dis),node});
                }
                bfs.push({i,dis+1});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<' ';
    }
    return 0;
}