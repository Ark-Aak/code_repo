#include <iostream>
#include <cstdio>
const int N=1000050;
int n,q;
struct node {
    int x,y;
}a[N];
int main() {
    freopen("ds.in","r",stdin);
    freopen("ds.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i].x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i].y);
    while(q--) {
        int u,r,d,l,ans=0;
        scanf("%d%d%d%d",&u,&r,&d,&l);
        for(int i=1;i<=n;i++) {
            if(a[i].x>u||a[i].x<d||a[i].y<l||a[i].y>r) continue;
            bool flag=true;
            for(int j=1;j<=n;j++) {
                if(i==j) continue;
                if(a[j].x>a[i].x&&a[j].x<=u&&a[j].y>a[i].y&&a[j].y<=r) {
                    flag=false;
                    break;
                }
            }
            if(flag) ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}