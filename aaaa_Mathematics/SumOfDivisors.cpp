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
int main(){
    ll n; cin>>n;
    ll sum = 0;
    ll last = 0;
    ll k = sqrt(n);
    for(ll i=k;i>=1;i--){
        sum = (sum+(n/i)*i)%mod1;
        if(last){
            ll now = n/i;
            ll a = 0, b = 0;
            if(now&1) a = (now%mod1)*(((now+1)/2)%mod1)%mod1;
            else a = ((now/2)%mod1)*(((now+1))%mod1)%mod1;
            if(last&1) b = (last%mod1)*(((last+1)/2)%mod1)%mod1;
            else b = ((last/2)%mod1)*(((last+1))%mod1)%mod1;
            int all = (a-b+mod1)%mod1;
            sum = (sum + all*i)%mod1;
            last = now;
        }
        else{
            last = n/i;
            if(last!=i){
                sum = (sum + last*i)%mod1;
            }
        }
    }
    cout<<sum<<endl;
}