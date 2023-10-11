#include <iostream>
#include <cstdio>
#include <bitset>
const int N=2050;
const int M=100500;
const int MOD=998244353;
int n,m,sum;
int f[2][M];
int main() {
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i) f[1][i]=1;
    for(int i=2;i<=n;++i) {
        int now=i&1;
        int pre=now^1;
        sum=0;
        for(int j=1;j<=m;++j) sum=(sum+f[pre][j])%MOD;
        for(int j=m;j>=1;--j) {
            f[now][j]=sum;
            for(int k=j<<1;k<=m;k+=j) f[now][j]=(f[now][j]-f[pre][k]+MOD)%MOD;
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++) ans=(ans+f[n&1][i])%MOD;
    printf("%d",ans);
    return 0;
}
