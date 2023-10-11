#include <iostream>
#include <cstdio>
const int N=200500;
int n,m,q;
int u[N],v[N];
int main() {
    freopen("journey.in","r",stdin);
    freopen("journey.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
    while(q--) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(c==d||c==u[a]&&d==v[a]||c==v[a]&&d==u[a]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}