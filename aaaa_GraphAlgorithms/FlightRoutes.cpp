#define PROGRAM int main(){rapid_iostream;int tc=1;;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
void swapp(int&a,int&b){int t=a;a=b;b=t;}
#define println(n) cout<<n<<'\n'
#define Y() cout<<"YES"<<endl
#define N() cout<<"NO"<<endl
#define MAIN void codeforce();
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
/***************************************************/ MAIN PROGRAM /*******************************************************/


const ll inf = 2e14;
void codeforce(){
    int n,m,k; cin>>n>>m>>k;
    vector<vector<pair<int,int>>> edge(n+1);
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edge[u].push_back({v,w});
    }
    vector<vector<ll>> cost(n+1,vector<ll>(k,inf));
    cost[1][0]=0;
    multiset<pair<ll,int>> st;
    st.insert({0,1});
    while(!st.empty()){
        auto it = st.begin();
        auto [costt,node] = *it;
        for(auto [u,c] : edge[node]){
            if(cost[u][k-1]>costt+c){
                auto itr=st.lower_bound({cost[u][k-1],u});
                if(itr->F==cost[u][k-1] && itr->S==u)st.erase(itr);
                cost[u][k-1]=costt+c;
                st.insert({cost[u][k-1],u});
                sort(cost[u].begin(),cost[u].end());
            }
        }
        st.erase(it);
    }
    for(auto i : cost[n]){
        cout<<i<<' ';
    }
}