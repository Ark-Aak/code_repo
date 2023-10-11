#include<bits/stdc++.h>
#define ll long long
#define N 40000005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll t,p;
bool vis[N];
vector<int> v;
void prime(){
    for(int i=2;i<=N;i++){
        if(!vis[i])v.push_back(i);
        for(int j=0;j<v.size();j++){
            if(i*v[j]>N)break;
            if(v[j]<=p)vis[i*v[j]]=1;
            if(i%v[j]==0)break;
        }
    }
}
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
int main(){
    freopen("casio.in","r",stdin);
    freopen("casio.out","w",stdout);
    t=fr();
    p=fr();
    prime();
    while(t--){
        ll n;
        n=fr();
        auto ed=lower_bound(v.begin(),v.end(),n);
        cout<<*ed<<endl;
    }
    return 0;
}