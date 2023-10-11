#include <iostream>
#include <cstdio>
const long long MOD = 998244353;
long long n,k;
int main() {
     freopen("flip.in","r",stdin);
     freopen("flip.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    if(n==k) printf("%lld",(n%MOD*n%MOD*n%MOD-n%MOD)%MOD>>1);
    else printf("%lld",n);
    return 0;
}
