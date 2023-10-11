#include <iostream>
#include <cstdio>
const int MOD=998244353;
const int N=5050;
int n,m;
int c[N];
int dfs(int step,int num,int combo) {
    if(combo>c[num]) return 0;
    if(step==n+1) return 1;
    int res=0;
    for(int i=1;i<=m;i++)
        if(i==num) res=(res+dfs(step+1,i,combo+1))%MOD;
        else res=(res+dfs(step+1,i,1))%MOD;
    return res;
}
int main() {
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);
    printf("%d",dfs(1,0,0));
    return 0;
}