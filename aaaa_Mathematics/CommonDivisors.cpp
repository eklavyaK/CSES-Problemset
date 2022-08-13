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
int tot[N];
int main(){
    rapid_iostream;
    int n; cin>>n;
    while(n--){
        int k; cin>>k;
        int till = sqrt(k);
        for(int i=1;i<=till;i++){
            if(k%i==0){
                tot[i]++;
                if(i!=k/i)tot[k/i]++;
            }
        }
    }
    int ans = 1;
    for(int i=1;i<=1000000;i++){
        if(tot[i]>1)ans = i;
    }
    cout<<ans<<endl;
    return 0;
}