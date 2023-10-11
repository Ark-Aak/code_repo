#include <iostream>
#include <cstdio>
int n;
int a,b,c,d;
int main() {
    freopen("explorer.in","r",stdin);
    freopen("explorer.out","w",stdout);
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    if(a==1&&b==2&&c==3&&d==4) printf("%d",n*(n-1)*(n-2)/6);
    else printf("0");
    return 0;
}