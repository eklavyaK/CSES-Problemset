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
using namespace std;                     //solved using permutation
int n,m;
ll ans = 0;
ll count_up(string a){              //function to count such numbers from integer 'a' to pow(10,a.size())-1
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll k = 9-(a[i]-'0');
        if(i && a[i]<a[i-1])k--;
        for(int j=i+1;j<n;j++)k*=9;
        ans+=k;
        if(i>0 && a[i]==a[i-1])break;
        if(i==n-1)ans++;
    }
    return ans;
}
ll count_down(string b){            //function to count such numbers from integer pow(10,b.size()) to integer 'b'
    ll ans = 0;
    for(int i=0;i<m;i++){
        ll k = b[i]-'0';
        if(!i || b[i]>b[i-1])k--;
        for(int j=i+1;j<m;j++)k*=9;
        ans+=k;
        if(i>0 && b[i]==b[i-1])break;
        if(i==m-1)ans++;
    }
    return ans;
}
int main(){
    rapid_iostream;
    string a,b; cin>>a>>b;
    n=a.size(); m=b.size();
    if(n==m){
        ll x = count_up(a);
        ll y = count_up(b);
        bool z = true;
        for(int i=1;i<m;i++){
            if(b[i]==b[i-1]){
                z=false;break;
            }
        }
        cout<<x-y+z;exit(0);
    }
    ans+=count_up(a);
    ans+=count_down(b);
    for(int i=n+1;i<m;i++){      //this loop counts such numbers from pow(10,a.size()) to pow(10,b.size())-1
        ll k = 1;
        for(int j=0;j<i;j++)k*=9;
        ans+=k;
    }
    cout<<ans;
    return 0;
}