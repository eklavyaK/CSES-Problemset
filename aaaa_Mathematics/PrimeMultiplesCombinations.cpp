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

vector<vector<ll>> ans;
vector<ll> track;
vector<ll> arr;
void Combinations(int start, int cnt , int r, int n){
    if(cnt == r){
        ans.push_back(track);
        return;
    }
    if(start == n)return;
    for(int i=start;i<n;i++){
        track.push_back(arr[i]);
        Combinations(i+1,cnt+1,r,n);
        track.pop_back();
    }
}
void nCr(int n,int r){
    ans.clear();
    track.clear();
    if(r>n)return;
    sort(arr.begin(),arr.end());
    Combinations(0,0,r,n);
}

int main(){
    rapid_iostream;
    ll n,k; cin>>n>>k;
    ll tot = 0;
    arr.resize(k);
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=k;i++){
        nCr(k,i);
        for(auto j : ans){
            ll prod = 1;
            for(auto x : j){
                ll ok = n/prod;
                if(x>ok)goto end;
                else prod*=x;
            }
            if(i&1)tot+=n/prod;
            else tot-=n/prod;
            end:;
        }
    }
    cout<<tot<<endl;
    return 0;
}