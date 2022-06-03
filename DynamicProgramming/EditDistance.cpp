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

    string s; cin>>s;
    string f; cin>>f;
    int n = s.size();
    int m = f.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        fill(dp[i],dp[i]+m+1,1e4);
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==f[j-1]){
                dp[i][j]=dp[i-1][j-1];        //if characters are same then no need to increase the edit distance of the prefix
            }
            else{
                dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1; //checking the minimum of insert, remove or replace operation
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}