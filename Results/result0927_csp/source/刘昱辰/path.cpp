#include<bits/stdc++.h>
#define ll long long
#define N 500
using namespace std;
const ll mod=1e9+7;
ll n,t;
ll mx[N][N],f[N][N],sum[N],a[N],g[N][N];
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
int main(){
    freopen("path.in","r",stdin);
    freopen("path.out","w",stdout);
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        mx[i][i]=fr();
        sum[i]=sum[i-1]+mx[i][i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j+i-1<=n;j++){
            mx[j][j+i-1]=max(mx[j+1][j+i-1],mx[j][j+i-2]);
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int j=0;j<=t;j++)f[1][j]=0,g[1][j]=mx[1][1];
    for(int i=2;i<=n;i++){
        for(int j=0;j<=t;j++){
            if(j==0){
                if(f[i][j]>mx[1][i]*i-sum[i]){
                    f[i][j]=mx[1][i]*i-sum[i];
                    g[i][j]=mx[1][1];
                }
                continue;
            }
            for(int k=1;k<=i;k++){
                if(g[k][j]>mx[k+1][i]&&f[i][j]>f[k][j]+(i-k)*g[k][j]-(sum[i]-sum[k])){
                    g[i][j]=g[k][j];
                    f[i][j]=f[k][j]+(i-k)*g[k][j]-(sum[i]-sum[k]);
                }
                if(j>0&&f[i][j]>f[k][j-1]+(i-k)*mx[k+1][i]-(sum[i]-sum[k])){
                    g[i][j]=mx[k+1][i];
                    f[i][j]=f[k][j-1]+(i-k)*mx[k+1][i]-(sum[i]-sum[k]);
                }
            }
        }
    }
    ll ans=INT_MAX;
    for(int j=0;j<=t;j++){
        ans=min(f[n][j],ans);
    }
    cout<<ans;
    return 0;
}