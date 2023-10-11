#include <iostream>
#include <cstdio>
#define int long long
const int N=1005;
const int MOD=1000000007;
int ans[N][N],sum[N][N];
inline int gcd(int x,int y){return !(x%y)?y:gcd(y,x%y);}
signed main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    for(int x=1;x<=1001;x++)
        for(int y=1;y<=1001;y++) {
            ans[x][y]=((x+y)/gcd(x,y)-2)%MOD;
            sum[x][y]=(sum[x-1][y]-sum[x-1][y-1]+sum[x][y-1]+ans[x][y])%MOD;
        }
    int T;
    for(scanf("%d",&T);T--;) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",sum[x][y]);
    }
    return 0;
}