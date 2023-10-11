
#include<bits/stdc++.h>
#define ll int
#define N 100005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll n,k;
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
namespace sol1{
    ll ans=0;
    struct qwq{
        ll g[N];
        bool friend operator==(const qwq &a,const qwq &b){
            for(int i=1;i<=n;i++)if(a.g[i]!=b.g[i])return 0;
            return 1;
        }
    }f[3],a,b;
    void solve(){
        const short mod=3;
        for(int i=1;i<=n;i++)f[0].g[i]=fr(),a.g[i]=f[0].g[i];
        for(int i=1;i<=n;i++)f[1].g[i]=fr(),b.g[i]=f[1].g[i];
        for(int i=2;i<=k;i++){
            ll x=i%mod,y=(i-2)%mod,z=(i-1)%mod;
            for(int j=1;j<=n;j++)f[x].g[f[y].g[j]]=f[z].g[j];
            if(f[x]==b&&f[z]==a){
                ans=i-1;
                break;
            }
        }
        if(ans==0){
            ll x=k%mod;
            for(int j=1;j<=n;j++)cout<<f[x].g[j]<<" ";
        }
        else {
            for(int i=1;i<=n;i++)f[0].g[i]=a.g[i],f[1].g[i]=b.g[i];
            for(int i=2;i<=ans;i++){
                ll x=i%mod,y=(i-2)%mod,z=(i-1)%mod;
                for(int j=1;j<=n;j++)f[x].g[f[y].g[j]]=f[z].g[j];
                if(k%ans==i){
                    for(int j=1;j<=n;j++)cout<<f[x].g[j]<<" ";
                    return ;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    n=fr();
    k=fr();
    sol1::solve();
    return 0;
}