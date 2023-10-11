#include <iostream>
#include <cstdio>
#define popc __builtin_popcount
const int N=25;
const int M=200050;
int n,m,ans;
int a[N][M],num[M];
inline void reverse_(int line) {
    for(int i=1;i<=m;i++) {
        num[i]^=(1<<(line-1));
        a[line][i]^=1;
    }
}
void solve() {
    int res=0;
    for(int i=1;i<=m;i++) res+=std::min(popc(num[i]),n-popc(num[i]));
    ans=std::min(ans,res);
}
void dfs(int step) {
    if(step==n) {
        solve();
        return;
    }
    dfs(step+1);
    reverse_(step);
    dfs(step+1);
    reverse_(step);
}
int main() {
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            scanf("%1d",&a[i][j]);
            num[j]=(num[j]<<1)|a[i][j];
        }
    ans=0x3f3f3f3f;
    dfs(1);
    printf("%d",ans);
    return 0;
}