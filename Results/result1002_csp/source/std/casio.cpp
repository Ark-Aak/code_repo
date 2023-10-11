#include<bits/stdc++.h>
using namespace std;
int prcnt,pr[30500000],f[30500000],fakecnt,fakepr[30500000];
const int maxn=30010000;
int T,P,n;
int main() {
    freopen("casio.in","r",stdin);
    freopen("casio.out","w",stdout);
    for (int i=2;i<=maxn;i++) {
        if (f[i]==0) pr[++prcnt]=i;
        for (int j=1;j<=prcnt;j++) {
            if (i*pr[j]>maxn) break;
            f[i*pr[j]]=pr[j];
            if (i%pr[j]==0) break;
        }
    }
    scanf("%d%d",&T,&P);
    for (int i=2;i<=maxn;i++) {
        if ((f[i]==0)||(f[i]>P)) fakepr[++fakecnt]=i;
    }
    while (T--) {
        scanf("%d",&n);
        int l=1,r=fakecnt,res=0,mid=0;
        while (l<=r) {
            mid=(l+r)/2;
            if (fakepr[mid]>=n) {
                res=mid;
                r=mid-1;
            } else l=mid+1;
        }
        printf("%d\n",fakepr[res]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}