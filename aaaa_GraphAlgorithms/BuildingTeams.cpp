#define PROGRAM int main(){rapid_iostream;int tc=1;while(tc-->0){codeforce();}return 0;}
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
const int N = 1e5+5;
vector<int> ans(N);
vector<int> check(N);
vector<vector<int>> f(N);
void dfs(int x){
    check[x]=1;
    for(auto i : f[x]){
        if(ans[i]==ans[x]){
            print("IMPOSSIBLE");
            exit(0);
        }
        ans[i]=ans[x]==1?2:1;
        if(!check[i])dfs(i);
    }
}
void codeforce(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v; cin>>u>>v;
        f[u].push_back(v);
        f[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            ans[i]=1;
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
}