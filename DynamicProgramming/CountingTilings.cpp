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

// Since number of rows is always less than 11, we try to represent a column using a binary, where 1 denote the column is filled and 0 denotes the empty cell in the column. We take the 1st column and check for all the possible ways it can be filled completely. At the same time take note of all the possible ways 2nd column is affected by the arrangement of 1st column. And while filling 2nd column we take note of how next column is affected and this process is repeated till 2nd last column
ll dp[1000][(1<<10)];
int main(){
    rapid_iostream;
    vector<int> c;   //if a column is partially empty then we check with all the binary numbers of vector 'c' which tells us all the possible arrangements of tiles that can be made in the empty cells. This vector basically contains numbers whose binary representation contains 1 in group of even numbers only like for n = 9 some contents of c are: 110000000, 011001100, 111100011      a number in c named c1 is anded with the existing column representation and it should be equal to 0 because if any of the places both numbers contain '1' then we cannot place a tile above another. Now if and operation is zero then places with 1 in c1 are filled completely with 1x2 tile, the places with 0 in c1 are filled with 1 cell of tile in existing column and other in next column which makes the place in next column filled and in binary representation of next column there will be 1 at that position 
    int n,m; cin>>n>>m;
    if(m%2){
        if(n%2){cout<<0;exit(0);}
        else if(m==1){cout<<n/2;exit(0);}
    }
    int z = (1<<n)-1;
    for(int i=0;i<=z;i++){
        bool t = true;
        for(int j=0;j<n;j++){
            if(!((1<<j)&i)){
                if(j+1>=n || (1<<j+1)&i){
                    t = false; break;
                }
                else j++;
            }
        }
        if(t){dp[1][i]++;c.push_back(i^z);}
    }
    for(int i=2;i<m;i++){
        for(int j=0;j<=z;j++){
            if(dp[i-1][j]){
                for(int k=0;k<c.size();k++){
                    if(!(j&c[k])){
                        dp[i][(j|c[k])^z]=(dp[i][(j|c[k])^z]+dp[i-1][j])%mod1;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<=z;i++){
        if(dp[m-1][i]){
            for(auto k : c){
                if(!(k&i) && (k|i)==z){
                    ans=(ans+dp[m-1][i])%mod1;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}