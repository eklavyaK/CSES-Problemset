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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pii, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    rapid_iostream;
    int n,k;cin>>n;
    ordered_set st;
    for(int i=0;i<n;i++){
        cin>>k;
        st.insert({i,k});
    }
    while(n--){
        int c; cin>>c;
        auto [in,u] = *st.find_by_order(c-1);
        st.erase({in,u});
        cout<<u<<' ';
    }
    return 0;
}