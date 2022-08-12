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
    int n,q;
    cin>>n>>q;
    int par[n+1][22];
    memset(par,0,sizeof(par));
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int k; cin>>k;
        par[i+2][0] = k;
        tree[i+2].push_back(k);
        tree[k].push_back(i+2);
    }
    queue<int> bfs;
    int dep[n+1]{};
    dep[1] = 0;
    bfs.push(1);
    while(!bfs.empty()){
        int node = bfs.front(); bfs.pop();
        for(auto i : tree[node]){
            if(i!=par[node][0]){
                dep[i] = dep[node]+1;
                bfs.push(i);
            }
        }
    }
    for(int i=1;i<22;i++){
        for(int j=1;j<=n;j++){
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    
    while(q--){
        int u,v; cin>>u>>v;
        if(dep[u]<dep[v])swap(u,v);
        int k = dep[u]-dep[v];
        for(int i=0;i<22;i++){
            if(k&(1<<i)){
                u = par[u][i];
            }
        }
        if(u==v){
            cout<<u<<endl;
            continue;
        }
        for(int i=21;i>=0;i--){
            if(par[u][i]!=par[v][i]){
                u = par[u][i];
                v = par[v][i];
            }
        }
        cout<<par[u][0]<<endl;
    }
    return 0;
}