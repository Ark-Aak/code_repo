#include <iostream>
#include <cstdio>
#include <cstring>
#define scnaf scanf
const int N=500050; 
int l[N],r[N];
bool ans[N];
int n,q;
int main() {
    freopen("badge.in","r",stdin);
    freopen("badge.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
    while(q--) {
        memset(ans,false,sizeof(ans));
        int m,res=0;
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            int tmp;
            scnaf("%d",&tmp);
            for(int j=1;j<=n;j++)
                if(l[j]<=tmp&&tmp<=r[j]) ans[j]^=1;
        }
        for(int j=1;j<=n;j++) res+=ans[j];
        printf("%d\n",res);
    }
    return 0;
}