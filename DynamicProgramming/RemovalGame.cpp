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
int main(){
    rapid_iostream;

    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll sum = 0;
    ll dp[n][n];
    for(int i=0;i<n;i++){
        dp[i][i]=a[i];
        sum+=a[i];
    }
    for(int i=1;i<n;i++){      //we go in reverse direction i.e. we calculate the maximum for first player for each subarray
        for(int j=0;j+i<n;j++){
            if(i%2)dp[j][j+i]=min(dp[j][j+i-1],dp[j+1][j+i]);
            else dp[j][j+i]=max(dp[j+1][j+i]+a[j],dp[j][j+i-1]+a[j+i]);
        }
    }
    if(n%2)cout<<dp[0][n-1];  //dp[0][n-1] gives the result for the player who removes the last element remaining
    else cout<<sum-dp[0][n-1];
    return 0;
}