#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
const ll mod=1e9+7;
ll n,m,f[N][50],g[N];
struct qwq{
    ll p,b,t;
}a[N];
struct qwq1{
    ll x,t,op;
}b[N];
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
ll ask(ll l,ll r){
    return min(f[l][g[r-l+1]],f[r-(1<<g[r-l+1])+1][g[r-l+1]]);
}
int main(){
    freopen("envelope.in","r",stdin);
    freopen("envelope.out","w",stdout);
    cin>>n>>m;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        a[i].p=fr();
        a[i].b=fr();
        a[i].t=fr();
    }
    ll cnt=0;
    for(int i=1;i<=m;i++){
        ll x=fr(),y=fr(),z=fr();
        for(int j=x;j<=y;j++){
            f[j][0]=min(f[j][0],z);
        }
    }
    for(int i=2;i<=n;i++)g[i]=g[i>>1]+1;
    for(int j=1;j<=g[n];j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(ask(i,a[i].p)<a[i].b)ans+=a[i].t;
    }
    cout<<ans;
    return 0;
}