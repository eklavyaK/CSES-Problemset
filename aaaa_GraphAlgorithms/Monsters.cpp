#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
void swapp(int&a,int&b){int t=a;a=b;b=t;}
#define println(n) cout<<n<<'\n'
#define Y() cout<<"YES"<<endl
#define N() cout<<"NO"<<endl
#define print(n) cout<<n<<' '
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
#define S second
#define F first
Compare(pii)
/***************************************************MAIN PROGRAM*******************************************************/
int n,m;
string s[1000];
queue<array<int,3>> q;
const int inf = 1e6+5;
int check[1000][1000];
int node_owner[1000][1000];
vector<vector<array<int,2>>> parent(1000, vector<array<int,2>>(1000));
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int r=0,c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='A'){
                r=i;c=j;
                check[i][j]=1;
                parent[i][j]={i,j};
                node_owner[i][j]=1;
            }
            else if(s[i][j]=='M'){
                check[i][j]=1;
                q.push({i,j,0});
            }
        }
    }
    q.push({r,c,1});
    while(!q.empty()){
        auto c = q.front(); q.pop();
        int i = c[0], j = c[1], node = c[2];
        if(i>0 && !check[i-1][j] && s[i-1][j]!='#'){
            check[i-1][j]=1;q.push({i-1,j,node});
            if(node){
                parent[i-1][j]={i,j};
                node_owner[i-1][j]=1;
            }
        }
        if(j>0 && !check[i][j-1] && s[i][j-1]!='#'){
            check[i][j-1]=1;q.push({i,j-1,node});
            if(node){
                parent[i][j-1]={i,j};
                node_owner[i][j-1]=1;
            }
        }
        if(i+1<n && !check[i+1][j] && s[i+1][j]!='#'){
            check[i+1][j]=1;q.push({i+1,j,node});
            if(node){
                parent[i+1][j]={i,j};
                node_owner[i+1][j]=1;
            }
        }
        if(j+1<m && !check[i][j+1] && s[i][j+1]!='#'){
            check[i][j+1]=1;q.push({i,j+1,node});
            if(node){
                parent[i][j+1]={i,j};
                node_owner[i][j+1]=1;
            }
        }
    }
    c=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||j==0||j==m-1||i==n-1){
                if(node_owner[i][j]==1){
                    r=i;c=j;break;
                }
            }
        }
    }
    if(c==-1)N();
    else{
        vector<char> ans;Y();
        while(true){
            if(parent[r][c][0]==r && parent[r][c][1]==c){
                break;
            }
            else if(parent[r][c][0]==r-1 && parent[r][c][1]==c){
                ans.push_back('D');r=r-1;
            }
            else if(parent[r][c][0]==r+1 && parent[r][c][1]==c){
                ans.push_back('U');r=r+1;
            }
            else if(parent[r][c][0]==r && parent[r][c][1]==c-1){
                ans.push_back('R');c=c-1;
            }
            else if(parent[r][c][0]==r && parent[r][c][1]==c+1){
                ans.push_back('L');c=c+1;
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto i : ans) cout<<i;
    }
}