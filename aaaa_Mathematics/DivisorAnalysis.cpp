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

int power(ll a, ll n){
    ll product = 1;
    while(n>0){
        if(n&1) product = (product*a) % mod1;
        n>>=1; a = (a*a) % mod1;
    }
    return product;
}
int modularInverse(int a, int mod){
    return power(a,mod-2);
}
int main(){
    rapid_iostream;
    int n; cin>>n;
    ll sum = 1, divisors = 1;
    vector<pair<ll,ll>> f;
    for(int i=0;i<n;i++){
        int x,p; cin>>x>>p;
        f.push_back({x,p});
/******************************* NUMBER OF DIVISORS *******************************/
        divisors = divisors*(p+1)%mod1;

/******************************* SUM OF DIVISORS *******************************/
        ll num = (power(x,p+1)-1+mod1)%mod1;
        ll den = modularInverse(x-1,mod1);
        int res = (num*den)%mod1;
        sum = (sum*res)%mod1;
    }
/******************************* PRODUCT OF DIVISORS *******************************/
    ll now = 1, tot[n];
    ll start[n+1], end[n+2];
    start[0] = 1; end[n+1] = 1;
    for(int i=1;i<=n;i++){
        now = now*(f[i-1].S+1)%(mod1-1);
        start[i] = now;
    }
    now = 1;
    for(int i=n;i>=1;i--){
        now = now*(f[i-1].S+1)%(mod1-1);
        end[i] = now;
    }
    for(int i=1;i<=n;i++){
        tot[i-1] = (start[i-1]*end[i+1])%(mod1-1);
    }
    ll product = 1;
    for(int i=0;i<n;i++){
        auto [x,p] = f[i];
        ll next = ((p*(p+1))>>1)%(mod1-1);
        product = (product*power(x,(next*tot[i])%(mod1-1)))%mod1;
    }
    cout<<divisors<<' '<<sum<<' '<<product;
    return 0;
}