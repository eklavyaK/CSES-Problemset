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
const int N = 2e5+5, LOG = 32;
int par[N], root[N], ans[N];
int cyclenumber[N], cnt = 1;
map<int,map<int,bool>> cycle;
map<int,int> cyclesize;
void dfs(int u, int k){
    cyclenumber[u]=k-1;
    if(cyclenumber[par[u]]==0){
        dfs(par[u],k-1);
    }
    if(cyclenumber[par[u]]<0){
        cyclesize[cnt] = cyclenumber[par[u]]-cyclenumber[u];
        cyclenumber[u] = cnt; cnt++; root[u]=1;
    }
    else{
        cyclenumber[u] = cyclenumber[par[u]];
    }
}
void calculate(int node){
    if(ans[par[node]]!=0){
        ans[node]=ans[par[node]]+1;
        return;
    }
    calculate(par[node]);
    ans[node]=ans[par[node]]+1;
}
int main(){
    rapid_iostream;
    int n; cin>>n; int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        par[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        if(cyclenumber[i]==0){
            dfs(i,0);
        }
    }
    for(int i=1;i<=n;i++){
        if(root[i]){
            int k = i;
            int num = cyclenumber[k];
            cycle[num][k]=true;
            while(par[k]!=i){
                k = par[k];
                cycle[num][k]=true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(cycle[cyclenumber[i]][i]){
            ans[i]=cyclesize[cyclenumber[i]]+1;
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            calculate(i);
        }
    }
    for(int i=1;i<=n;i++)
    cout<<ans[i]<<' ';cout<<endl;
    return 0;
}