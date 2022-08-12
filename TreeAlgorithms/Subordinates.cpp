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
    int par[n+1]{};
    int indeg[n+1]{}, cnt[n+1]{};
    for(int i=0;i<n-1;i++){
        int k; cin>>k;
        par[i+2] = k;
        indeg[k]++;
    }
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front(); q.pop();
        indeg[par[now]]--;
        cnt[par[now]]+=(cnt[now]+1);
        if(indeg[par[now]]==0){
            if(par[now]==1)break;
            q.push(par[now]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}