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
int vis[N],ans[N],n,m,cnt=1;           
vector<vector<int>> graph(N);
vector<vector<int>> revgraph(N); 
stack<int> comps;                  
void dfs(int node){
    vis[node]=1;
    for(auto i : graph[node]){
        if(!vis[i]) dfs(i);
    }
    comps.push(node);
}
void revdfs(int node){
    vis[node]=0; ans[node] = cnt;
    for(auto i : revgraph[node]){
        if(vis[i]) revdfs(i);
    }
}
void SCC(){
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    while(!comps.empty()){
        int c = comps.top();
        comps.pop();
        if(!vis[c])continue;
        revdfs(c); cnt++;
    }
}
int main(){
    rapid_iostream;
    cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }
    SCC(); cout<<cnt-1<<endl;
    for(int i=1;i<=n;i++)
    cout<<ans[i]<<' ';cout<<endl;
    return 0;
}