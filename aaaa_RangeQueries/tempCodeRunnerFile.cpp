#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define MAIN void codeforce();
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
/***************************************************/ MAIN PROGRAM /*******************************************************/


void codeforce(){
    int n; cin>>n;
    map<int,int> m;
    int mx = 0, cnt = 0;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        m[k]++;
        mx = max(mx,k);
    }
    for(auto i : m) if(i.S==1)cnt++;
    vector<int> v;
    for(auto j : m){
        v.push_back(j.F);
    }
    reverse(v.begin(),v.end());
    int mn = cnt;
    for(int i=1;i<=mx;i++){
        map<int,int> now = m;cnt = 0;
        for(auto j : v){
            if(!now.count(j))continue;
            if(now[j]==1){
                if(now.count(j-i)){
                    if(now[j-i]<=2)
                    now.erase(j-i);
                }
                else if(now.count(j+i)){
                    now.erase(j);
                }
                else cnt++;
            }
        }
        mn = min(mn,cnt);
    }
    cout<<n-mn<<endl;
}