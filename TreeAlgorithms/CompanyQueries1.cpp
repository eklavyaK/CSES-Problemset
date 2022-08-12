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
    int n,q;
    cin>>n>>q;
    int par[n+1][23];
    memset(par,0,sizeof(par));
    for(int i=0;i<n-1;i++){
        int k; cin>>k;
        par[i+2][0] = k;
    }
    for(int i=1;i<23;i++){
        for(int j=1;j<=n;j++){
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    while(q--){
        int node,k;
        cin>>node>>k;
        for(int i=0;i<23;i++){
            if(k&(1<<i))node = par[node][i];
        }
        if(node==0)cout<<-1<<endl;
        else cout<<node<<endl;
    }
    return 0;
}