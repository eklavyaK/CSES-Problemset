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
int dp[505][505];
int main(){
    rapid_iostream;
    int a1,b1; cin>>a1>>b1;
    int a = min(a1,b1);
    int b = max(a1,b1);
    for(int i=1;i<=a;i++){
        fill(dp[i]+1,dp[i]+b+1,1e3);
    }
    for(int i=1;i<=a;i++){
        for(int j=i;j<=b;j++){  //calculating the minimum lines for each and every rectangle with length less than equal to 'a' and breadth less than equal to 'b' where 'a' is less than 'b'
            if(j%i==0){
                dp[i][j]=j/i-1; //if breadth is divisible by length then answer will always be j/i - 1 as minimum
            }
            else{
                for(int k=1;k<i;k++){ //we know that for every ractangle there will be a smallest square the corner which can be made possible at first by drawing two lines in three different ways, in two such cases two other rectangles will be formed and in one of the cases three rectangles will be formed apart from the smallest square
                    dp[i][j]=min(dp[i][j],min({dp[k][j-k]+dp[i-k][j],dp[i-k][k]+dp[i][j-k],dp[k][j-k]+dp[i-k][k]+dp[i-k][b-k]})+2);
                }
                dp[i][j]=min(dp[i][j],dp[i][j-i]+1);  //we can also check for the largest square that is possible right now in the rectangle which side will be equal to the length of the smallest side of the current rectangle by drawing only one line in the rectangle
            }
            dp[j][i]=dp[i][j];  //swapping the length and breadth dimensions doesn't change the value of the result for the rectangle
        }
    }
    cout<<dp[a][b];
    return 0;
}