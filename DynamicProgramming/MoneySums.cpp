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
int check[100005];
int main(){
    rapid_iostream;

    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int l = a[0];
    int r = l;
    for(int i=1;i<n;i++){
        r+=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=r;j>=l;j--){
            if(check[j]){
                check[j+a[i]]=1;
            }
        }
        check[a[i]]=1;
    }
    int ans = 0;
    for(int i=l;i<=r;i++){
        if(check[i])ans++;
    }
    cout<<ans<<'\n';
    for(int i=l;i<=r;i++){
        if(check[i])
        cout<<i<<' ';
    }

    return 0;
}