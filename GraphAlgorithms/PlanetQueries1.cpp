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
 
//simple binary lifting problem
 
int main(){
    rapid_iostream;
    int n,q; cin>>n>>q;
    int ancestor[n+1][30];
    for(int i=1;i<=n;i++){
        cin>>ancestor[i][0];
    }
    for(int i=1;i<30;i++){
        for(int j=1;j<=n;j++){
            ancestor[j][i]=ancestor[ancestor[j][i-1]][i-1];
        }
    }
    while(q--){
        int x,k;cin>>x>>k;
        for(int i=0;i<30;i++){
            if((1<<i)&k){
                x = ancestor[x][i];
            }
        }
        cout<<x<<endl;
    }
    return 0;
}