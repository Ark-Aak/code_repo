#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define int long long
#define FI for(int i=1;i<=n;i++)
#define FJ for(int j=1;j<=m;j++)
#define FDI for(int i=n;i>=k;i--)
#define FDJ for(int j=m;j>=k;j--)
#define FUI for(int i=k;i<=n;i++)
#define FUJ for(int j=k;j<=m;j++)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)//偷个懒
using namespace std;
int mp[2000][2000];
int a[2000][2000],b[2000][2000],c[2000][2000],d[2000][2000];
int n,m,k;
signed main(){
    //freopen("C:\\Users\\pc\\Desktop\\input.txt","r",stdin);
    scanf("%lld%lld",&n,&k);
	m = n;
    int x;
    int cnt=1;
    FI FJ{
        //printf("%d\n",cnt++);
        scanf("%lld",&x);
        mp[i][j]=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1]+x;
    }
    FDI FDJ    mp[i][j]-=mp[i-k][j]+mp[i][j-k]-mp[i-k][j-k];//mp的意义是以i，j为右下角的K*K正方形的石油储量之和
    FUI FUJ    a[i][j]=max(mp[i][j],max(a[i-1][j],a[i][j-1]));
    FUI FDJ b[i][j]=max(mp[i][j],max(b[i-1][j],b[i][j+1]));
    FDI FUJ c[i][j]=max(mp[i][j],max(c[i+1][j],c[i][j-1]));
    FDI FDJ d[i][j]=max(mp[i][j],max(d[i+1][j],d[i][j+1]));//初始化abcd
    int ans=0;
    rep(i,k,n-k) rep(j,k,m-k) ans=max(ans,a[i][j]+b[i][j+k]+c[i+k][m]);
    rep(i,k,n-k) rep(j,k,m-k) ans=max(ans,a[i][m]+c[i+k][j]+d[i+k][j+k]);
    rep(i,k,n-k) rep(j,k,m-k) ans=max(ans,a[i][j]+b[n][j+k]+c[i+k][j]);
    rep(i,k,n-k) rep(j,k,m-k) ans=max(ans,a[n][j]+b[i][j+k]+d[i+k][j+k]);
    rep(i,k,n-k) rep(j,k+k,m-k) ans=max(ans,a[n][j-k]+b[n][j+k]+mp[i][j]);
    rep(i,k+k,n-k) rep(j,k,m-k) ans=max(ans,a[i-k][m]+c[i+k][m]+mp[i][j]);
    //更新答案
    printf("%lld",ans);
    return 0;
}
