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
vector<int> ans;
const int N=1e5+5;
int check[N],n,m,dist;
vector<int> dists(N,N);
vector<int> distf(N,N);
vector<vector<int>> edge(N);
void dfs(int d, int x){
    ans.push_back(x);
    check[x]=1;
    if(x==n){
        cout<<dist+1<<endl;
        for(auto i : ans) cout<<i<<' ';
        exit(0);
    }
    for(auto i : edge[x]){
        if(d+1+distf[i]==dist && !check[i]){
            dfs(d+1,i);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v; cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dists[1]=0;
    set<array<int,2>> st;
    st.insert({0,1});
    while(!st.empty()){
        auto c = *st.begin();
        if(dists[n]<=c[0]+1)break;
        for(auto i : edge[c[1]]){
            if(dists[i]>c[0]+1){
                st.erase({dists[i],i});
                dists[i]=c[0]+1;
                st.insert({c[0]+1,i});
            }
        }
        st.erase(c);
    }
    if(dists[n]==N){
        print("IMPOSSIBLE");
        exit(0);
    }
    else dist=dists[n];
    st.clear();
    distf[n]=0;
    st.insert({0,n});
    while(!st.empty()){
        auto c = *st.begin();
        if(distf[1]<=c[0]+1)break;
        for(auto i : edge[c[1]]){
            if(distf[i]>c[0]+1){
                st.erase({distf[i],i});
                distf[i]=c[0]+1;
                st.insert({c[0]+1,i});
            }
        }
        st.erase(c);
    }
    dfs(0,1);
    return 0;
}