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
const int N = 3.5e4;
vector<int> graph[N];
int vis[N],n,k;
string ans;
void dfs(int node){
    vis[node]=1;
    for(auto u : graph[node]){
        if(vis[u])continue;
        if(u&1)ans+='1';
        else ans+='0';
        dfs(u); break;
    }
}
int main(){
    rapid_iostream;
    cin>>n;k = pow(2,n)-1;
    for(int i=0;i<=k;i++){
        int c = (i<<1)&k;
        if((c|1)!=i)graph[i].push_back(c|1);
        if(c!=i)graph[i].push_back(c);
    }
    ans = string(n,'0');
    dfs(0);
    cout<<ans<<endl;
    return 0;
}