#include<bits/stdc++.h>
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;

    int n,x; cin>>n>>x;
    int a[n];map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    for(int i=0;i<n;i++){
        if((x-a[i]!=a[i] && m.count(x-a[i]))){
            cout<<i+1<<' ';
            for(int j=0;j<n;j++){
                if(j!=i && a[j]==x-a[i]){
                    cout<<j+1;
                    goto end;
                }
            }
        }
        else if((x-a[i]==a[i]&&m[a[i]]>1)){
            cout<<i+1<<' ';
            for(int j=0;j<n;j++){
                if(j!=i && a[j]==x-a[i]){
                    cout<<j+1;
                    goto end;
                }
            }
        }
    }
    print("IMPOSSIBLE");end:;
    return 0;
}