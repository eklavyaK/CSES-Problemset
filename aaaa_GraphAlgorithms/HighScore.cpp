#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
void swapp(int&a,int&b){int t=a;a=b;b=t;}
#define println(n) cout<<n<<'\n'
#define Y() cout<<"YES"<<endl
#define N() cout<<"NO"<<endl
#define print(n) cout<<n<<' '
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
#define S second
#define F first
Compare(pii)
/***************************************************MAIN PROGRAM*******************************************************/
map<int,bool> check;
vector<vector<array<int,2>>> edge(2505);
const ll mn = -5e12-5;
bool visited[2505];
vector<int> track;
int n,m; 
void dfs(int x){
    visited[x]=true;
    track.push_back(x);
    if(x==n){
        for(auto i : track)check[i];
        visited[x]=false;
        track.pop_back();
        return;
    }
    for(auto i : edge[x]){
        if(!visited[i[0]]){
            dfs(i[0]);
        }
    }
    track.pop_back();
    visited[x]=false;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edge[u].push_back({v,w});
    }
    bool detect = false;
    vector<ll> dist(n+1,mn);
    dist[1]=0;vector<ll> s,f;
    for(int i=1;i<=n+5;i++){
        for(int j=1;j<=n;j++){
            for(auto [node,w]:edge[j]){
                dist[node] = max(dist[node],dist[j]+w);
            }
        }
        if(i==n-1){
            s=dist;
        }
        if(i==n+5){
            f=dist;
        }
    }
    if(s!=f){
        dfs(1);
        for(int i=1;i<=n;i++){
            if(s[i]!=f[i] && check.count(i)){
                print(-1);exit(0);
            }
        }
        cout<<dist[n];
    }
    else cout<<dist[n];
    return 0;
}