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
vector<vector<int>> edge(200005);
int check[100005];
int parent[100005];
void display_cycle(int i, int x){
    int cnt = 2;
    ans.push_back(i);
    while(x!=i){
        ans.push_back(x);
        x = parent[x];
        cnt++;
    }
    ans.push_back(i);
    cout<<ans.size()<<endl;
    for(auto i : ans)cout<<i<<' ';
}
void dfs(int x){
    check[x]=1;
    for(auto i : edge[x]){
        if(!check[i]){
            parent[i]=x;
            dfs(i);
        }
        else if(parent[x]!=i){
            display_cycle(i,x);
            exit(0);
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    parent[1]=1;
    for(int i=1;i<=n;i++){
        if(!check[i])dfs(i);
    }
    print("IMPOSSIBLE");
    return 0;
}