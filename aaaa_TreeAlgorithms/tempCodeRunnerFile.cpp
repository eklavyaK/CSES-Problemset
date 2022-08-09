#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************MAIN PROGRAM*******************************************************/

int counter;
vector<int> prime;
set<int> store;
void sieve(int n){
set<int> st;
counter=0;prime.clear();
int checker = sqrt(n);
for(int i=2;i<=n;i++){
    if(st.count(i))continue;
    prime.push_back(i);
    store.insert(i);
    if(i<=checker)
    for(int j=i*i;j<=n;j+=i)
    if(!st.count(j))st.insert(j);
    counter++;
}
}

int main(){
    rapid_iostream;
    int n; cin>>n;
    sieve(n); int ans = 0;
    for(int i=0;i<counter-1;i++){
        if(store.count(prime[i]+prime[i+1]+1)){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}