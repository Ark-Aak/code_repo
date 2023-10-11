#include<bits/stdc++.h>
#define ll long long
#define N 2000005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
vector<ll> v[N];
ll siz[N],f[N],g[N],n;
void dfs(ll x,ll fa){
    for(auto y:v[x]){
        if(y==fa)continue;
        dfs(y,x);
        siz[x]+=siz[y];
        f[x]+=f[y];
    }
    for(auto y:v[x]){
        if(y==fa)continue;
        f[x]+=x*siz[y]*(siz[x]-siz[y]);
    }
    f[x]+=2*siz[x]*x+x;
    siz[x]++;
}
void dfs2(ll x,ll fa){
    for(auto y:v[x]){
        if(y==fa)continue;
        g[y]=g[x]+(y-x)*2*(siz[y])*(n-siz[y]);
        dfs2(y,x);
    }
}
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("lca.in","r",stdin);
    freopen("lca.out","w",stdout);
    n=fr();
    for(ll i=1;i<n;i++){
        ll x=fr();
        ll y=fr();
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    g[1]=f[1];
    dfs2(1,0);
    for(ll i=1;i<=n;i++)cout<<g[i]<<" ";
    return 0;
}