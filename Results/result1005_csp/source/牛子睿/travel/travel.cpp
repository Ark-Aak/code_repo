#include <iostream>
#include <cstdio>
int n,k,m,ans=1;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=m;i++) {
        int s;
        scanf("%*d%*d%d",&s);
        if(s) ans=0;
    }
    if(k==0) printf("%d",ans);
    else printf("ÍæÔ­ÉñÍæµÄ");
    return 0;
}            
