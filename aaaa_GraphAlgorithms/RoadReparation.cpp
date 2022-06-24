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
const int N = 1e5+5, inf = 1e9+5;
vector<vector<pair<int,int>>> node(N);

int main(){
    rapid_iostream;
    int n,m; cin>>n>>m;
    while(m--){
        int u,v,c; cin>>u>>v>>c;
        node[u].push_back({v,c});
        node[v].push_back({u,c});
    }
    vector<int> cost(n+1,inf);
    ll ans = 0; 
    cost[1]=0;
    bool check[n+1]{};
    set<pair<int,int>> st;
    st.insert({0,1});
    while(!st.empty()){
        auto [c,u] = *st.begin();
        ans += c; check[u]=true;
        for(auto [nod,cos] : node[u]){
            if(!check[nod]){
                if(cost[nod]>cos){
                    st.erase({cost[nod],nod});
                    cost[nod] = cos;
                    st.insert({cost[nod],nod});
                }
            }
        }
        st.erase({c,u});
    }

    for(int i=1;i<=n;i++){
        if(cost[i]==inf){
            print("IMPOSSIBLE");
            return 0;
        }
    }
    cout<<ans;
    return 0;
}