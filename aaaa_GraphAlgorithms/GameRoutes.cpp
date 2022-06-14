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
    int cnt[n+1]{};
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        edge[u].push_back(v);
    }
    set<int> st;
    int check[n+1]{};
    vector<int> ans(n+1);
    queue<int> bfs; 
    bfs.push(1);
    st.insert(1);
    check[1] = 1;
    while(!bfs.empty()){
        int k = bfs.front(); bfs.pop();
        for(auto i : edge[k]){
            if(!check[i]){
                st.insert(i);
                check[i]=1;
                bfs.push(i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(st.find(i)!=st.end())
        for(auto k : edge[i]){
            cnt[k]++;
        }
    }
    bfs.push(1);
    ans[1] = 1;
    while(!bfs.empty()){
        int k = bfs.front(); bfs.pop();
        for(auto i : edge[k]){
            ans[i]=(ans[i]+ans[k])%mod1;
            cnt[i]--;if(cnt[i]==0){
                bfs.push(i);
            }
        }
    }
    cout<<ans[n];
    return 0;
}