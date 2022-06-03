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

    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> ans(n+1,1e9+5);
    ans[0]=0;
    for(int i=0;i<n;i++){
        int k = upper_bound(ans.begin(),ans.end(),a[i])-ans.begin();
        if(ans[k-1]<a[i] && ans[k]>a[i]) ans[k]=a[i];  //insertion is done middle to cover all the possibilities
    }
    int result = 1;
    for(int i=0;i<=n;i++){
        if(ans[i]<1e9+5){
            result=i;
        }
    }
    cout<<result;
    return 0;
}