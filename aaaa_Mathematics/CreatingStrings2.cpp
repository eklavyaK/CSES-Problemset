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

ll binaryExponentiation(ll a, ll n){
    ll ans = 1;
    while(n>0){
        if(n&1) ans = (ans*a)%mod1;
        a = (a*a)%mod1; n>>=1;
    }
    return ans;
}
ll modularInverse(ll a, ll mod){
    return binaryExponentiation(a,mod-2);
}
const int N = 1e6+5;
ll fact[N];
void factorial(int n){
    fact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i] = (fact[i-1]*i)%mod1;
    }
}
int main(){
    rapid_iostream;
    string s; cin>>s;
    int n = s.size();
    factorial(n);
    int cnt[26]{};
    for(int i=0;i<n;i++){
        cnt[s[i]-'a']++;
    }
    ll ans = fact[n];
    for(int i=0;i<26;i++){
        ans = (ans*modularInverse(fact[cnt[i]],mod1))%mod1;
    }
    cout<<ans<<endl;
    return 0;
}