#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
void swapp(int&a,int&b){int t=a;a=b;b=t;}
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
 
const int N = 200005;
int a[N]; int tree[4*N];
void SegmentTree(int node, int l, int r){
    if(l==r){
        tree[node]=a[l];
        return;
    }
    int mid = (l+r)/2;
    SegmentTree(2*node,l,mid);
    SegmentTree(2*node+1,mid+1,r);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}
int query(int node, int l, int r, int st, int en){
    if(l>en || r<st)return 1e9;
    if(st<=l && en>=r)return tree[node];
    int mid = (l+r)/2;
    return min(query(2*node,l,mid,st,en),query(2*node+1,mid+1,r,st,en));
}
int main(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    SegmentTree(1,1,n);
    while(q--){
        int u,v; cin>>u>>v;
        cout<<query(1,1,n,u,v)<<endl;
    }
    return 0;
}