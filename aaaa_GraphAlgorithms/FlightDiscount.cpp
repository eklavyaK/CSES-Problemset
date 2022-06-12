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
const ll inf = 2e14;
int main(){
    int n,m; cin>>n>>m;
    vector<vector<array<int,2>>> edges(n+1);
    vector<vector<array<int,2>>> edgef(n+1);
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edges[u].push_back({v,w});
        edgef[v].push_back({u,w});
    }
    vector<ll> costs(n+1,inf);
    vector<ll> costf(n+1,inf);
    costf[n]=0;costs[1]=0;
    set<pair<ll,int>> st;
    st.insert({0,1});
    while(!st.empty()){
        auto [cost,node] = *st.begin();
        for(auto [i,w] : edges[node]){
            if(costs[i]>costs[node]+w){
                st.erase({costs[i],i});
                costs[i]=cost+w;
                st.insert({costs[i],i});
            }
        }
        st.erase({cost,node});
    }
    st.insert({0,n});
    while(!st.empty()){
        auto [cost,node] = *st.begin();
        for(auto [i,w] : edgef[node]){
            if(costf[i]>costf[node]+w){
                st.erase({costf[i],i});
                costf[i]=cost+w;
                st.insert({costf[i],i});
            }
        }
        st.erase({cost,node});
    }
    ll ans = inf;
    for(int i=1;i<=n;i++){
        for(auto [node,w] : edgef[i]){
            ans=min(costs[node]+costf[i]+w/2,ans);
        }
    }
    cout<<ans;
    return 0;
}