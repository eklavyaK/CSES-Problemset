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
    ll ans = cost[n];
    set<int> nodes;
    for(int i=1;i<=n;i++){
        for(auto [nod,c] : edge[i]){
            if(nod==n && cost[i]+c==ans){
                nodes.insert(i);
            }
        }
    }
    queue<int> q;
    q.push(1);
    int cnt[n+1]{};
    int check[n+1]{};
    check[1]=1;
    set<int> tot;
    tot.insert(1);
    while(!q.empty()){
        int k = q.front();q.pop();
        for(auto [nod,c] : edge[k]){
            if(check[nod]) continue;
            check[nod]=1;
            q.push(nod);
            tot.insert(nod);
        }
    }
    for(int i=1;i<=n;i++){
        if(tot.find(i)!=tot.end())
        for(auto [nod,c] : edge[i]){
            cout<<i<<' '<<nod<<endl;
            cnt[nod]++;
        }
    }
    queue<int> bfs;
    bfs.push(1);
    ll num[n+1]{};
    num[1] = 1;
    while(!bfs.empty()){
        int k = bfs.front(); bfs.pop();
        for(auto [node, c]: edge[k]){
            num[node] = (num[node]+num[k])%mod1;
            cnt[node]--;if(cnt[node]==0){
                q.push(node);
            }
        }
    }
    for(auto i : num) cout<<i<<' ';cout<<endl;
    int ways = 0;
    for(auto i : nodes){
        ways=(ways+num[i])%mod1;
    }
    vector<int> mnn(n+1,100000);
    st.insert({0,1});
    mnn[1] = 0;int mn = 100000;
    while(!st.empty()){
        auto [msn,node] = *st.begin();
        for(auto [u,c] : edge[node]){
            if(mnn[u]>msn+1){
                st.erase({mnn[u],u});
                mnn[u]=msn+1;
                st.insert({mnn[u],u});
            }
            if(u==n && nodes.find(node)!=nodes.end()){
                mn = min(mn,mnn[node]+1);
            }
        }
        st.erase({msn,node});
    }
    vector<int> mxn(n+1,0);
    st.insert({0,1});
    mxn[1]=0;int mx = 0;
    while(!st.empty()){
        auto [mxx,node] = *st.begin();
        for(auto [u,c] : edge[node]){
            if(mxn[u]<mxx+1){
                st.erase({mxn[u],u});
                mxn[u]=mxx+1;
                st.insert({mxn[u],u});
            }
            if(u==n && nodes.find(node)!=nodes.end()){
                mx=max(mx,mxn[node]+1);
            }
        }
        st.erase({mxx,node});
    }
    cout<<ans<<' '<<ways<<' '<<mn<<' '<<mx;
    return 0;
}