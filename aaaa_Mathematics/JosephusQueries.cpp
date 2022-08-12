#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream cin.tie(0)->sync_with_stdio(0)
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
set<int> st;
int t = 0;
int josephus(int first, int start, int end, int diff, int rem){
    int k = (end-start)/diff+1;
    if(rem<=k){
        rem--;
        return min(start+rem*diff,end);
    }
    rem-=k;
    if((end-start)%diff){
        if(start==first) return josephus(first+diff/2,first+diff/2,end,diff*2,rem);
        else return josephus(first,first,end,diff*2,rem);
    }
    else{
        if(start==first) return josephus(first+diff/2,first+3*diff/2,end-diff/2,diff*2,rem);
        else return josephus(first,first+diff,end-diff/2,diff*2,rem);
    }
}
int main(){
    rapid_iostream;
    int n; cin>>n;
    while(n--){
        int c,k; cin>>c>>k;
        if(c==1) cout<<1<<endl;
        else cout<<josephus(1,2,c,2,k)<<endl;
    }
    return 0;
}