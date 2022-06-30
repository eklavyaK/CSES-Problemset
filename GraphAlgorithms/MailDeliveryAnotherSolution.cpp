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
vector<int> graph[N];
unsigned int n,m, cnt[N], track[N];
map<int,bool> edge[N];
vector<int> route;
bool check(){
    for(int i=1;i<=n;i++)
    if(cnt[i]%2)return false;
    int vis[n+1]{};
    queue<int> bfs;
    bfs.push(1);vis[1]=1;
    while(!bfs.empty()){
        int node = bfs.front(); bfs.pop();
        for(auto i : graph[node]){
            if(vis[i])continue;
            vis[i]=1;bfs.push(i);
        }
    }
    for(int i=1;i<=n;i++)
    if(!vis[i]&&cnt[i]!=0)return false;
    return true;
}
void dfs(int node){
    for(;track[node]<graph[node].size();){
        if(edge[node][graph[node][track[node]]]){
            edge[node][graph[node][track[node]]]=false;
            edge[graph[node][track[node]]][node]=false;
            dfs(graph[node][track[node]]);
        }
        else track[node]++;
    }
    route.push_back(node);
}
int main(){
    rapid_iostream;
    cin>>n>>m;
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        cnt[u]++; cnt[v]++;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edge[u][v]=true;
        edge[v][u]=true;
    }
    if(!check()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    dfs(1);
    reverse(route.begin(),route.end());
    for(auto i : route) cout<<i<<' ';
    return 0;
}