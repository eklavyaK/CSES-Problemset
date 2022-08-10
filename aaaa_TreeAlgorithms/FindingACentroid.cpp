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



int main(){
    rapid_iostream;
    int n; cin>>n;
    int indeg[n+1]{};
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        indeg[u]++;indeg[v]++;
    }
    queue<int> bfs;
    int cnt[n+1]{};
    int done[n+1]{};
    for(int i=1;i<=n;i++){
        if(indeg[i]==1){bfs.push(i);done[i]=1;cnt[i]=1;}
    }
    int a = 1, b = 0;
    while(!bfs.empty()){
        int node = bfs.front(); bfs.pop();
        a = node;
        for(auto i : tree[node]){
            if(!done[i]){
                if(cnt[i]+1+cnt[node]>n/2){
                    a = i; b = node; break;
                }
                cnt[i]+=(cnt[node]);
                indeg[i]--;
                if(indeg[i]==1){
                    done[i] = 1; cnt[i]++;
                    bfs.push(i);
                }
            }
        }
    }
    function<int(int,int)> check = [&](int node, int par){
        int tot = 0;
        for(auto i : tree[node]){
            if(i==par)continue;
            int k = check(i,node);
            tot+=k;
        }
        return tot+1;
    };
    int mx = 0;
    for(auto i : tree[a]){
        mx = max(check(i,a),mx);
    }
    if(mx<=n/2)cout<<a<<endl;
    else cout<<b<<endl;
    return 0;
}