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
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main(){
    ordered_set<pii> st;
    int n,q; cin>>n>>q; int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st.insert({a[i],i});
    }
    while(q--){
        char c; cin>>c;
        if(c=='!'){
            int pos,now;cin>>pos>>now;
            auto it = st.lower_bound({a[pos],pos});
            st.erase(it);a[pos]=now;
            st.insert({now,pos});
        }
        else{
            int l,r; cin>>l>>r;
            cout<<st.order_of_key({r+1,0}) -
            st.order_of_key({l,0})<<endl;
        }
    }
    return 0;
}