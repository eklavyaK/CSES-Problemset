#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
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

const int N = 1005;
int dp[N][N];
int main(){
    rapid_iostream;
    int n, q; cin>>n>>q;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        string s; cin>>s;
        for(int j=1;j<=n;j++){
            if(s[j-1]=='*')cnt++;
            dp[i][j]=dp[i-1][j]+cnt;
        }
    }
    while(q--){
        int a,b,u,v;
        cin>>a>>b>>u>>v;
        cout<<dp[u][v]+dp[a-1][b-1]-dp[u][b-1]-dp[a-1][v]<<endl;
    }
    return 0;
}