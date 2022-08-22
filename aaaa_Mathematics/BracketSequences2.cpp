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

const int N = 1e6+5;
ll fact[N];
void factorial(int n){
    fact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i] = (fact[i-1]*i)%mod1;
    }
}
ll power(ll a, ll n){
    ll ans = 1;
    while(n>0){
        if(n&1) ans = (ans*a)%mod1;
        n>>=1; a = (a*a)%mod1;
    }
    return ans;
}
ll modularInverse(ll a){
    return power(a, mod1-2);
}
ll nCr(ll n, ll r){
    return (fact[n]*modularInverse(fact[n-r])%mod1)*modularInverse(fact[r])%mod1;
}
int main(){
    rapid_iostream;
    int n; cin>>n;
    string s; cin>>s;
    factorial(n);
    int cnt = 0, open = 0;
    if(n&1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            cnt++;open++;
        }
        else cnt--;
        if(cnt<0){
            cout<<0<<endl;
            return 0;
        }
        else if(open>n/2){
            cout<<0<<endl;;
            return 0;
        }
    }
    n /= 2; n = n-(s.size()-cnt)/2-cnt;
    if (n<0) {
        cout<<0<<"\n";
    } else {
        cout<<nCr(2*n + cnt, n)*(cnt + 1)%mod1*modularInverse(n + cnt + 1)%mod1<<endl;
    }
    return 0;
}