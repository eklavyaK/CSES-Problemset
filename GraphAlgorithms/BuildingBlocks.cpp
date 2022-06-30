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

const int N = 1e5;
int parent[N+1];
int szn[N+1];
void make(int n){
    for(int i=0;i<=n;i++){
        parent[i]=i;szn[i]=1;
    }
}
int parent_set(int x){
    if(x==parent[x])return x;
    return parent[x]=parent_set(parent[x]);
}
void merge_sets(int u, int v){
    u = parent_set(u);v = parent_set(v);
    if(u!=v){
        if(szn[u]<szn[v])swapp(u,v);
        parent[v]=u; szn[u]+=szn[v];
    }
}
int main(){
    int n,m; cin>>n>>m;
    make(n);
    for(int i=0;i<m;i++){
        int u, v; cin>>u>>v;
        merge_sets(u,v);
    }
    set<int> st;
    for(int i=1;i<=n;i++){
        parent[i]=parent_set(i);
    }
    for(int i=1;i<=n;i++){
        st.insert(parent[i]);
    }
    cout<<st.size()-1<<endl;
    int k = *st.begin();
    st.erase(k);
    for(auto i : st){
        cout<<k<<' '<<i<<endl;
        k=i;
    }
}