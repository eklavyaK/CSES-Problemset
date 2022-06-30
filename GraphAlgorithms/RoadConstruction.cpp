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
int par[N], sz[N], ansmx = 1, n, m;
vector<vector<int>> node(N);
void makeset(int tot){
    for(int i=1;i<=tot;i++){
        par[i]=i; sz[i]=1;
    }
}
int findset(int u){
    if(par[u]==u){
        return u;
    }
    return par[u] = findset(par[u]);
}
void merge_sets(int u, int v){
    u = findset(u);
    v = findset(v);
    if(u!=v){
        if(sz[u]<sz[v])swap(u,v);
        par[v]=u;--n;
        sz[u] += sz[v];
        ansmx = max(ansmx,sz[u]);
        cout<<n<<' '<<ansmx<<endl;
    }
    else cout<<n<<' '<<ansmx<<endl;
}
int main(){
    rapid_iostream;
    cin>>n>>m;
    makeset(n);
    while(m--){
        int u,v; cin>>u>>v;
        merge_sets(u,v);
    }
    return 0;
}