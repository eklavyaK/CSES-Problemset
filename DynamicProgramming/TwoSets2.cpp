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
ll dp[62626];
int main(){
    rapid_iostream;

    int n; cin>>n;
    int sum = n*(n+1)/2;
    if(sum%2){
        cout<<0;    //obviously if the sum is odd it's equal halves cannot be a integer
        return 0;
    }
    sum/=2;dp[1]=1; //a subset having required sum will either contain 1 or not contain 1. Here we count all the subsets containing 1 to because there will always be a disjoint set for each subset containing 1 whose summation is also equal to sum
    for(int i=2;i<=n;i++){
        for(int j=sum;j>=1;j--){
            if(j-i>=0 && dp[j-i]){
                dp[j]=(dp[j]+dp[j-i])%mod1;
            }
        }
    }
    cout<<dp[sum];
    return 0;
}