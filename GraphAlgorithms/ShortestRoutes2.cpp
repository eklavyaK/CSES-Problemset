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
int n,m,q; 
const ll inf = 5e11+5;
vector<vector<ll>> dist(501,vector<ll>(501,inf));
void calculate(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
void query(int u, int v){
    if(dist[u][v]==inf)
    {println(-1);return;}
    cout<<dist[u][v]<<endl;
}
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],(ll)w);
        dist[v][u]=dist[u][v];
    }
    calculate();
    while(q--){
        int u, v; cin>>u>>v;
        query(u,v);
    }
    return 0;
}