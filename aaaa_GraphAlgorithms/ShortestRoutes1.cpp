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
const ll inf = 1e14;
const int N = 1e5+5;
vector<vector<array<int,2>>> edge(N);
vector<ll> dist(N,inf);
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edge[u].push_back({v,w});
    }
    dist[1]=0;
    set<array<ll,2>> st;
    st.insert({0,1});
    while(!st.empty()){
        auto c=*st.begin();
        for(auto i : edge[c[1]]){
            if(dist[i[0]]>c[0]+i[1]){
                st.erase({dist[i[0]],i[0]});
                dist[i[0]]=c[0]+i[1];
                st.insert({c[0]+i[1],i[0]});
            }
        }
        st.erase(c);
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<' ';
    }
    return 0;
}