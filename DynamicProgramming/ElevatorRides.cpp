#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#define least int,vector<int>,greater<int>
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
array<array<int,2>,(1<<20)> dp;
int main(){
    rapid_iostream;

    int n; cin>>n;
    int x; cin>>x;
    int a[n];
    for(auto &i:a)cin>>i;
    dp[0][0]=0;dp[0][1]=0;
    for(int i=1;i<(1<<n);i++){
        dp[i][0]=n;
        dp[i][1]=x;
    }
    for(int i=0;i<(1<<n);i++){         //using position bitmasking
        for(int j=0;j<n;j++){
            if((1<<j)&i)continue;
            int next = i|(1<<j);
            if(dp[i][1]+a[j]>x){
                dp[next]=min(dp[next],{dp[i][0]+1,a[j]}); //if weight of the person exceeds x at last ride an extra ride must be done for him, we calculate the minimum of the no. of rides with previous cases when same combination of persons were travelling
            }
            else{
                dp[next]=min(dp[next],{dp[i][0],dp[i][1]+a[j]});  //adding the weight of current person to the existing last elevator ride and calculating the minimum with the previous cases when same combinations of person were added
            }
        }
    }
    cout<<dp[(1<<n)-1][0]+1;   //1 is added because after when dp[i][0] increases to 1 only after 1 elevator is already full so next person can only go next time elevators arrives
    return 0;
}