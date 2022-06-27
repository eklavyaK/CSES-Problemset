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
int n,m,indeg[N],outdeg[N];
vector<int> route;
vector<int> track(N);
bool check(){
    if(outdeg[1]-indeg[1]!=1 || indeg[n]-outdeg[n]!=1){
        return false;
    }
    for(int i=2;i<n;i++){
        if(outdeg[i]!=indeg[i])return false;
    }
    int vis[n+1]{};
    queue<int> q;
    q.push(1);vis[1] = 1;
    while(!q.empty()){
        int node = q.front();q.pop();
        for(auto i : graph[node]){
            if(!vis[i]) {
                q.push(i);
                vis[i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i] && (indeg[i]!=0||outdeg[i]!=0)){
            return false;
        }
    }
    return true;
}
void dfs(int node){
    for(;track[node]<graph[node].size();){
        dfs(graph[node][track[node]++]);
    }
    route.push_back(node);
}
int main(){
    rapid_iostream;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        indeg[v]++;outdeg[u]++;
    }
    if(!check()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    dfs(1);
    reverse(route.begin(),route.end());
    for(auto i : route){
        cout<<i<<' ';
    }
    return 0;
}