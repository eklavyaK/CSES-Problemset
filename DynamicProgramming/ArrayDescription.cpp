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
ll dp[100005][105];
int main(){
    rapid_iostream;

    int n;cin>>n;
    int a[n+1];
    int m;cin>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]){
        dp[1][a[1]]=1;
    }
    else{
        for(int j=1;j<=m;j++){
            dp[1][j]=1;
        }
    }
    for(int i=2;i<=n;i++){
        if(!a[i]){
            for(int j=1;j<=m;j++){
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod1;
            }
        }
        else dp[i][a[i]]=(dp[i-1][a[i]-1]+dp[i-1][a[i]]+dp[i-1][a[i]+1])%mod1;
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        ans = (ans+dp[n][i])%mod1;
    }
    cout<<ans;

    return 0;
}