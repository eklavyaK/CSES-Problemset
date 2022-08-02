#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
void swapp(int&a,int&b){int t=a;a=b;b=t;}
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
    int n,q;cin>>n>>q;int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    ll sum[n]; sum[0]=a[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    while(q--){
        int u,v; cin>>u>>v;
        u--;v--;
        if(u==0){
            cout<<sum[v]<<endl;
        }
        else cout<<sum[v]-sum[u-1]<<endl;
    }
    return 0;
