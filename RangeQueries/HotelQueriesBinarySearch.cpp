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
int tree[N*4], a[N];
int pos, decrement, st=1, en, n, m, cap;
void SegmentTree(int node, int l, int r){
    if(l==r){
        tree[node] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    SegmentTree(2*node,l,mid);
    SegmentTree(2*node+1,mid+1,r);
    tree[node] = max(tree[2*node],tree[2*node+1]);
}
void update(int node ,int l, int r){
    if(l==r){
        tree[node]-=decrement;
        return;
    }
    int mid = (l+r)>>1;
    if(pos<=mid) update(2*node,l,mid);
    else update(2*node+1,mid+1,r);
    tree[node]=max(tree[node*2],tree[2*node+1]);
}
int query(int node, int l, int r){
    if(st>r || en<l) return 0;
    if(st<=l && en>=r){
        return tree[node];
    }
    int mid = (l+r)>>1;
    return max(query(2*node,l,mid),query(2*node+1,mid+1,r));
}
int get(){
    int l = 1, r = n;
    while(l<r){
        int mid = (l+r)>>1;
        en = mid;
        int q = query(1,1,n);
        if(q>=cap)r = mid;
        else l = mid+1;
    }
    return r;
}
int main(){
    rapid_iostream;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    SegmentTree(1,1,n);
    while(m--){
        cin>>cap;
        pos = get();
        if(a[pos]<cap){
            cout<<0<<' ';
            continue;
        }
        else a[pos]-=cap;
        decrement = cap;
        cout<<pos<<' ';
        update(1,1,n);
    }
    return 0;
}