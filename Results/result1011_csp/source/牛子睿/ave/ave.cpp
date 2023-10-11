#include <iostream>
#include <cstdio>
#include <algorithm>
const int N=1000050;
int n;
double a[N];
int main() {
    freopen("ave.in","r",stdin);
    freopen("ave.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
    std::sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) a[i]=(a[i-1]+a[i])/2;
    printf("%.6lf",a[n]);
    return 0;
}