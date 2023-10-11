#include <iostream>
#include <cstdio>
long long n;
int main() {
    freopen("lca.in","r",stdin);
    freopen("lca.out","w",stdout);
    scanf("%lld",&n);
    printf("%lld",(n+1)*n*n*(n-1)/2);
    return 0;
}