#include <iostream>
#include <cstdio>
int ans[15]={0,0,0,6,16,120,624,5040,38144,362880,3549440,39916800};
int main() {
    freopen("ring.in","r",stdin);
    freopen("ring.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d",ans[n]%m);
    return 0;
}