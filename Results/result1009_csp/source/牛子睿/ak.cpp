#include <iostream>
#include <cstdio>
#include <algorithm>
const int N=1000050;
int n,k,sum;
int a[N];
int task2[N];
int main() {
    freopen("ak.in","r",stdin);
    freopen("ak.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        task2[i]=a[i];
        sum+=a[i];
    }
    if(k==1) {
        std::sort(task2+1,task2+n+1);
        printf("%d",sum-task2[(n+2)>>1]);
        return 0;
    }
    printf("%d",sum-a[1]);
    return 0;
}