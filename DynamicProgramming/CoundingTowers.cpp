#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pii pair<int,int>
#define mod2 998244353ll
#define mod1 1000000007ll
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
const int M=1e6+5;
ll dp[M][2];
int main(){
    rapid_iostream;
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<M-4;i++){
        dp[i][0]=(dp[i][0]+dp[i-1][0]*2+dp[i-1][1])%mod1;
        dp[i][1]=(dp[i][1]+dp[i-1][1]*4+dp[i-1][0])%mod1;
    }
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        cout<<(dp[n][0]+dp[n][1])%mod1<<endl;
    }
    return 0;
}