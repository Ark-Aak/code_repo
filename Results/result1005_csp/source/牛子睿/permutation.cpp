#include <iostream>
#include <cstdio>
const int N=100050;
int n,k,rnd=-1;
int data1[N],data2[N],p[N][3];
int seed[N];
int main() {
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",&data1[i]);
        p[i][0]=data1[i];
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&data2[i]);
        p[i][1]=data2[i];
    }
    for(int i=2;i<=k;i++) {
        int now=i%3;
        int pre1=(i+2)%3;
        int pre2=(i+1)%3;
        for(int j=1;j<=n;j++) p[p[j][pre2]][now]=p[j][pre1];
        bool flag=true;
        for(int j=1;j<=n;j++)
            if(p[j][pre1]!=data1[j]) flag=false;
        for(int j=1;j<=n;j++)
            if(p[j][now]!=data2[j]) flag=false;
        if(flag) {
            rnd=i-1;
            break;
        }
    }
    if(rnd==-1)
        for(int i=1;i<=n;i++) printf("%d ",p[i][k%3]);
    else {
        k%=rnd;
        for(int i=2;i<=k;i++) {
            int now=i%3;
            int pre1=(i+2)%3;
            int pre2=(i+1)%3;
            for(int j=1;j<=n;j++) p[p[j][pre2]][now]=p[j][pre1];
        }
        for(int i=1;i<=n;i++) printf("%d ",p[i][k%3]);
    }
    return 0;
}
