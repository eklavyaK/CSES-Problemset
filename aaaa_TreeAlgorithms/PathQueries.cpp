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
int main(){
    rapid_iostream;
    int n,q; cin>>n>>q; 
    int arr[2*n+1]{}, now[n+1]{};
    vector<vector<int>> tree(n+1);
    for(int i=1;i<=n;i++)cin>>now[i];
    for(int i=0;i<n-1;i++){
        int u,k; cin>>u>>k;
        tree[u].push_back(k);
        tree[k].push_back(u);
    }
    int index=1;
    vector<pair<int,int>> pos(n+1);
    function<void(int)> dfs = [&](int node){
        arr[index] = now[node]; pos[node].F = index++;
        for(auto i : tree[node]){
            if(!pos[i].F)dfs(i);
        }
        arr[index] = -now[node]; pos[node].S = index++;
    };
    dfs(1);
    ll Tree[4*index+5]{};
    function<void(int,int,int)> SegmentTree = [&](int node, int l, int r){
        if(l==r){
            Tree[node] = arr[l];
            return;
        }
        int mid = (l+r)>>1;
        SegmentTree(2*node,l,mid);
        SegmentTree(2*node+1,mid+1,r);
        Tree[node] = Tree[2*node]+Tree[2*node+1];
    };
    function<void(int,int,int,int,int)> update = [&](int node, int l, int r, int idx, int value){
        if(l==r){
            Tree[node] = value;
            return;
        }
        int mid = (l+r)>>1;
        if(idx<=mid) update(2*node,l,mid,idx,value);
        else update(2*node+1,mid+1,r,idx,value);
        Tree[node] = Tree[2*node]+Tree[2*node+1];
    };
    function<ll(int,int,int,int,int)> query = [&](int node, int l, int r, int st, int en){
        if(l>en || r<st) return 0ll;
        else if(st<=l && en>=r) return Tree[node];
        int mid = (l+r)>>1;
        return query(2*node,l,mid,st,en) + query(2*node+1,mid+1,r,st,en);
    };
    SegmentTree(1,1,index);
    while(q--){
        int type; cin>>type;
        if(type==1){
            int s,x; cin>>s>>x;
            update(1,1,index,pos[s].F,x);
            update(1,1,index,pos[s].S,-x);
        }
        else{
            int s; cin>>s;
            cout<<query(1,1,index,1,pos[s].F)<<endl;
        }
    }
    return 0;
}