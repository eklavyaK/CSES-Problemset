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

const int N = 2e5+5;
ll tree[N*4],a[N],cn,ans;
void SegmentTree(int node, int l, int r){
    if(l==r){
        tree[node]=a[l];
        return;
    }
    int mid = (l+r)>>1;
    SegmentTree(2*node,l,mid);
    SegmentTree(2*node+1,mid+1,r);
}
void update(int node, int l, int r, int st, int en){
    if(st>r || en<l){
        return;
    }
    if(st<=l && en>=r){
        tree[node]+=cn;
        return;
    }
    int mid = (l+r)>>1;
    update(2*node,l,mid,st,en);
    update(2*node+1,mid+1,r,st,en);
}
void query(int node, int l, int r, int pos){
    ans+=tree[node];
    if(l==r) return;
    int mid = (l+r)>>1;
    if(pos<=mid) query(2*node,l,mid,pos);
    else query(2*node+1,mid+1,r,pos);
}
int main(){
    rapid_iostream;
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    SegmentTree(1,1,n);
    while(q--){
        int type; cin>>type;
        if(type==1){
            int u,v; cin>>u>>v>>cn;
            update(1,1,n,u,v);
        }
        else{
            int pos; cin>>pos;
            ans = 0; query(1,1,n,pos);
            cout<<ans<<endl;
        }
    }
    return 0;
}