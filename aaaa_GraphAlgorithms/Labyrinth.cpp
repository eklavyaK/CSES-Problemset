#include<bits/stdc++.h>
#define N() cout<<"NO"<<endl
#define Y() cout<<"YES"<<endl
typedef long double ld;
typedef long long ll;
using namespace std;
const int inf = 1e6+1;
int check[1000][1000];
int dist;string s[1000];
vector<char> ans;int n,m;
vector<vector<int>> dista(1000,vector<int>(1000,inf));
vector<vector<int>> distb(1000,vector<int>(1000,inf));
void dfs(int d, int i, int j){
    check[i][j]=1;
    if(s[i][j]=='B'){
        Y();cout<<dist<<endl;
        for(auto i : ans)cout<<i;
        exit(0);
    }
    if(i>0 && s[i-1][j]!='#' && !check[i-1][j] &&d+1+distb[i-1][j]<=dist){
        ans.push_back('U');dfs(++d,i-1,j);
    }
    if(j>0 && s[i][j-1]!='#' && !check[i][j-1] &&d+1+distb[i][j-1]<=dist){
        ans.push_back('L');dfs(++d,i,j-1);
    }
    if(i+1<n && s[i+1][j]!='#' && !check[i+1][j] &&d+1+distb[i+1][j]<=dist){
        ans.push_back('D');dfs(++d,i+1,j);
    }
    if(j+1<m && s[i][j+1]!='#' && !check[i][j+1] &&d+1+distb[i][j+1]<=dist){
        ans.push_back('R');dfs(++d,i,j+1);
    }
}
int main(){cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
    int a=-1,b,r=-1,c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='A'){
                a=i;b=j;
            }
            else if(s[i][j]=='B'){
                r=i;c=j;
            }
        }
        if(a!=-1 && r!=-1)break;
    }
    set<array<int,3>> st;
    st.insert({0,a,b});
    dista[a][b]=0;
    while(!st.empty()){
        auto x = *st.begin();
        if(x[0]>=dista[r][c])break;
        else if(dista[r][c]==abs(r-a)+abs(c-b))break;
        if(x[1]>0 && s[x[1]-1][x[2]]!='#'){
            if(x[0]+1<dista[x[1]-1][x[2]]){
                st.erase({dista[x[1]-1][x[2]],x[1]-1,x[2]});
                dista[x[1]-1][x[2]]=x[0]+1;
                st.insert({dista[x[1]-1][x[2]],x[1]-1,x[2]});
            }
        }
        if(x[2]>0 && s[x[1]][x[2]-1]!='#'){
            if(x[0]+1<dista[x[1]][x[2]-1]){
                st.erase({dista[x[1]][x[2]-1],x[1],x[2]-1});
                dista[x[1]][x[2]-1]=x[0]+1;
                st.insert({dista[x[1]][x[2]-1],x[1],x[2]-1});
            }
        }
        if(x[1]+1<n && s[x[1]+1][x[2]]!='#'){
            if(x[0]+1<dista[x[1]+1][x[2]]){
                st.erase({dista[x[1]+1][x[2]],x[1]+1,x[2]});
                dista[x[1]+1][x[2]]=x[0]+1;
                st.insert({dista[x[1]+1][x[2]],x[1]+1,x[2]});
            }
        }
        if(x[2]+1<m && s[x[1]][x[2]+1]!='#'){
            if(x[0]+1<dista[x[1]][x[2]+1]){
                st.erase({dista[x[1]][x[2]+1],x[1],x[2]+1});
                dista[x[1]][x[2]+1]=x[0]+1;
                st.insert({dista[x[1]][x[2]+1],x[1],x[2]+1});
            }
        }
        st.erase(x);
    }
    if(dista[r][c]==inf){N();exit(0);}
    else dist = dista[r][c];
    st.clear();
    st.insert({0,r,c});
    distb[r][c]=0;
    while(!st.empty()){
        auto x = *st.begin();
        if(x[0]>=distb[a][b])break;
        else if(distb[a][b]==abs(r-a)+abs(c-b))break;
        if(x[1]>0 && s[x[1]-1][x[2]]!='#'){
            if(x[0]+1<distb[x[1]-1][x[2]]){
                st.erase({distb[x[1]-1][x[2]],x[1]-1,x[2]});
                distb[x[1]-1][x[2]]=x[0]+1;
                st.insert({distb[x[1]-1][x[2]],x[1]-1,x[2]});
            }
        }
        if(x[2]>0 && s[x[1]][x[2]-1]!='#'){
            if(x[0]+1<distb[x[1]][x[2]-1]){
                st.erase({distb[x[1]][x[2]-1],x[1],x[2]-1});
                distb[x[1]][x[2]-1]=x[0]+1;
                st.insert({distb[x[1]][x[2]-1],x[1],x[2]-1});
            }
        }
        if(x[1]+1<n && s[x[1]+1][x[2]]!='#'){
            if(x[0]+1<distb[x[1]+1][x[2]]){
                st.erase({distb[x[1]+1][x[2]],x[1]+1,x[2]});
                distb[x[1]+1][x[2]]=x[0]+1;
                st.insert({distb[x[1]+1][x[2]],x[1]+1,x[2]});
            }
        }
        if(x[2]+1<m && s[x[1]][x[2]+1]!='#'){
            if(x[0]+1<distb[x[1]][x[2]+1]){
                st.erase({distb[x[1]][x[2]+1],x[1],x[2]+1});
                distb[x[1]][x[2]+1]=x[0]+1;
                st.insert({distb[x[1]][x[2]+1],x[1],x[2]+1});
            }
        }
        st.erase(x);
    }
    dfs(0,a,b);
    return 0;
}