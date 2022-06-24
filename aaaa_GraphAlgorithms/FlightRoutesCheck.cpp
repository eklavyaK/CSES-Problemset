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

const int N = 1e5+5;       //simple concept is that if you can visit all the nodes from a node and also visit the same node from all the nodes then we can visit all the nodes from any node. For ex:- if 1 is visited by all the nodes and we can visit all the nodes from 1. so to visit node 'a' from some node 'b' we can always visit first node 1 from node 'b' (because 1 is visited from all the nodes) then visit the node 'a' from node 1 (all the nodes can visited from node 1)
int vis[N];
vector<vector<int>> graph(N);
vector<vector<int>> reversegraph(N);   
void dfs(int node){
    for(auto i : graph[node]){
        if(vis[i])continue;
        vis[i]=1;dfs(i);
    }
}
void second_dfs(int node){
    for(auto i : reversegraph[node]){
        if(vis[i])continue;
        vis[i]=1;second_dfs(i);
    }
}
int main(){
    rapid_iostream;
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        reversegraph[v].push_back(u);
    }
    dfs(1);
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            N(); cout<<1<<' '<<i<<endl;
            return 0;
        }
    }
    fill(vis,vis+n+1,0);
    second_dfs(1);
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            N(); cout<<i<<' '<<1<<endl;
            return 0;
        }
    }
    Y(); 
    return 0;
}