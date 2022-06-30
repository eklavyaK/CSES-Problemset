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



int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> edge(n+1);
    for(int j=0;j<m;j++){
        int u,v; cin>>u>>v;
        edge[u].push_back(v);
    }
    int parent[n+1];
    vector<int> num(n+1);
    parent[1]=1;num[1]=1;
    set<pair<int,int>> st;
    st.insert({1,1});
    while(!st.empty()){
        auto [nm,node] = *st.begin();
        for(auto u : edge[node]){
            if(num[u]<nm+1){
                st.erase({num[u],u});
                num[u]=nm+1;
                st.insert({num[u],u});
                parent[u] = node;
            }
        }
        st.erase({nm,node});
    }
    if(num[n]==0)print("IMPOSSIBLE");
    else{
        vector<int> ans;
        while(n!=1){
            ans.push_back(n);
            n=parent[n];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto i : ans) cout<<i<<' ';
    }
    return 0;
}