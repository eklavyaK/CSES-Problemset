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
    rapid_iostream;
    ll n,k; cin>>n>>k;
    vector<ll> arr(k);
    for(int i=0;i<k;i++)cin>>arr[i];
    ll ans = 0; int all = (1<<k);
    for(int  i=1;i<all;i++){
        ll prod = 1;
        for(int  j=0;j<k;j++){
            if((1<<j)&i){
                if(arr[j]<=n/prod)prod*=arr[j];
                else goto end;
            }
        }
        if(__builtin_popcount(i)&1)ans+=n/prod;
        else ans-=n/prod;
        end:;
    }
    cout.precision(20);
    cout<<ans<<endl;
    return 0;
}