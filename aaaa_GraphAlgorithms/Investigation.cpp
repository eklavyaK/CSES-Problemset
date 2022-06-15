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
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************MAIN PROGRAM*******************************************************/

const ll inf = 2e14;

int main(){
    int  n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> edge(n+1);
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edge[u].push_back({v,w});
    }
    vector<ll> cost(n+1,inf);
    set<pair<ll,int>> st;
    cost[1]=0;
    st.insert({0,1});
    while(!st.empty()){
        auto [costt,node]=*st.begin();
        for(auto [u,c] : edge[node]){
            if(cost[u]>costt+c){
                st.erase({cost[u],u});
                cost[u]=costt+c;
                st.insert({cost[u],u});
            }
        }
        st.erase({costt,node});
    }
    int check[n+1]{};
    int cnt[n+1]{};
    for(int i=1;i<=n;i++){
        for(auto [node,c] : edge[i]){
            if(cost[node]==cost[i]+c){
                cnt[node]++;
            }
        }
    }
    vector<int> mn(n+1,100000);
    vector<int> mx(n+1);
    mn[1]=0;mx[1]=0;
    vector<int> ways(n+1,0);
    queue<int> bfs;
    bfs.push(1);
    ways[1]=1;
    while(!bfs.empty()){
        int k = bfs.front(); bfs.pop();
        for(auto [node,c] : edge[k]){
            if(cost[node]==cost[k]+c){
                mx[node]=max(mx[node],mx[k]+1);
                mn[node]=min(mn[node],mn[k]+1);
                ways[node]=(ways[node]+ways[k])%mod1;
                cnt[node]--; if(cnt[node]==0){
                    bfs.push(node);
                }
            }
        }
    }
    cout<<cost[n]<<' '<<ways[n]<<' '<<mn[n]<<' '<<mx[n];
}