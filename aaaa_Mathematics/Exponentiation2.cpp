#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream cin.tie(0)->sync_with_stdio(0)
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
ll power(ll a, ll n, ll mod){
    ll ans = 1;
    while(n>0){
        if(n&1)ans = (ans*a)%mod;
        a = (a*a)%mod; n>>=1;
    }
    return ans;
}
int main(){
    rapid_iostream;
    int n; cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        int r = power(b,c,1000000006);
        cout<<power(a,r,1000000007)<<endl;
    }
}