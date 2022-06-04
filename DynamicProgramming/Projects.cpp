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
using namespace std;
const int N = 2e5+5;
ll tree[4*N];
void update(int node, int l, int r, int pos, ll val){    //updating the segment tree after every ending time
    if(l==r){
        tree[node]=val;
        return;
    }
    int mid = (l+r)/2;
    if(pos<=mid)update(2*node,l,mid,pos,val);
    else update(2*node+1,mid+1,r,pos,val);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
ll query(int node, int l, int r, int st, int en){
    if(l>en || st>r)return 0;
    else if(st<=l && en>=r)return tree[node];
    int mid = (l+r)/2;
    return max(query(2*node,l,mid,st,en),query(2*node+1,mid+1,r,st,en));
}
int main(){
    rapid_iostream;

    int n;cin>>n;               //this question can also be done using dp with similar approach as LIS problem
    multiset<pii> s;
    vector<array<int,3>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i][1]>>v[i][0]>>v[i][2];
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(s.size()==0){
            ans = max(ans,(ll)v[i][2]);
            update(1,0,n-1,i,v[i][2]);
            s.insert({v[i][0],i});
            continue;
        }
        auto it = s.lower_bound({v[i][1],0});
        if(it->F>=v[i][1] && it==s.begin()){
            ans = max(ans,(ll)v[i][2]);
            update(1,0,n-1,i,v[i][2]);
            s.insert({v[i][0],i});
            continue;
        }
        else it--;
        ll k = query(1,0,n-1,0,it->S);
        ans = max(ans,k+v[i][2]);
        update(1,0,n-1,i,k+v[i][2]);
        s.insert({v[i][0],i});
    }
    cout<<ans<<endl;

    return 0;
}