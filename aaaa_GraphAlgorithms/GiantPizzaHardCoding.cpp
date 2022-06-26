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
const int N = 1e5+5;
set<int> v[N],inv[N];
int main(){
    rapid_iostream;
    int n,m; cin>>n>>m;
    int cnt[m+1]{};
    vector<pair<int,int>> tops;
    for(int i=1;i<=n;i++){
        char ca, cb; int ina,inb;
        cin>>ca>>ina>>cb>>inb;
        if(ca=='-' && cb=='-'){
            inv[ina].insert(-inb);
            inv[inb].insert(-ina);
            tops.push_back({-ina,-inb});
        }
        else if(ca=='+' && cb=='-'){
            v[ina].insert(-inb);
            inv[inb].insert(ina);
            tops.push_back({ina,-inb});
        }
        else if(ca=='-' && cb=='+'){
            inv[ina].insert(inb);
            v[inb].insert(-ina);
            tops.push_back({-ina,inb});
        }
        else{
            v[ina].insert(inb);
            v[inb].insert(ina);
            tops.push_back({ina,inb});
        }
        cnt[ina]++;cnt[inb]++;
    }
    vector<char> ans(m+1,'$');
    bool check[m+1]{};
    for(auto [x,y] : tops){
        if(x==y && !check[abs(x)]){
            if(x<0){
                check[-x]=true;
                ans[-x] = '-';
            }
            else{
                check[x]=true;
                ans[x] = '+';
            }
        }
        else if(x==y){
            if(check[abs(x)]!=(x<0?'-':'+')){
                print("IMPOSSIBLE");
                return 0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        bool next = false;
        for(auto x : inv[i]){
            if(x==i)continue;
            if(inv[i].find(-x)!=inv[i].end()){
                if(check[i] && ans[i]=='+'){
                    print("IMPOSSIBLE");
                    return 0;
                }
                ans[i] = '-';
                check[i] = true;
                next = true;
                break;
            }
        }
        for(auto x : v[i]){
            if(x==i)continue;
            if(v[i].find(-x)!=v[i].end()){
                if(next){
                    print("IMPOSSIBLE");
                    return 0;
                }
                else if(check[i] && ans[i]=='-'){
                    print("IMPOSSIBLE");
                    return 0;
                }
                else{
                    check[i] = true;
                    ans[i] = '+';
                    break;
                }
            }
        }
    }
    queue<int> q;
    for(int i=1;i<=m;i++){
        if(cnt[i]==1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int k = q.front();q.pop();
        if(check[k])continue;
        if(inv[k].size()){
            int x = *inv[k].begin();
            inv[k].erase(x);
            check[k]=true;
            ans[k]='-';
            if(x<0){
                x=-x;
                inv[x].erase(-k);
                cnt[x]--;
                if(cnt[x]==1)q.push(x);
            }
            else{
                v[x].erase(-k);
                cnt[x]--;
                if(cnt[x]==1)q.push(x);
            }
        }
        else{
            int x = *v[k].begin();
            v[k].erase(x);
            check[k]=true;
            ans[k]='+';
            if(x<0){
                x=-x;
                inv[x].erase(k);
                cnt[x]--;
                if(cnt[x]==1)q.push(x);
            }
            else{
                v[x].erase(k);
                cnt[x]--;
                if(cnt[x]==1)q.push(x);
            }
        }
    }
    // for(int i=1;i<=m;i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    for(auto [x,y] : tops){
        if(check[abs(x)] && ans[abs(x)]!=(x<0?'-':'+')){
            if(check[abs(y)] && ans[abs(y)]!=(y<0?'-':'+')){
                print("IMPOSSIBLE");return 0;
            }
        }
        else if(check[abs(y)] && ans[abs(y)]!=(y<0?'-':'+')){
            if(check[abs(x)] && ans[abs(x)]!=(x<0?'-':'+')){
                print("IMPOSSIBLE");return 0;
            }
        }
        if(ans[abs(x)]!=(x<0?'-':'+') && ans[abs(y)]!=(y<0?'-':'+')){
            if(!check[abs(x)]){
                ans[abs(x)]=(x<0?'-':'+');
                check[abs(x)]=true;
            }
            else{
                ans[abs(y)]=(y<0?'-':'+');
                check[abs(y)]=true;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(!check[i])ans[i]='-';
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}