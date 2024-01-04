#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+5;
int a[500005],b[500005],ma[500005],vis[500005],sum[500005],pre[500005];
int t[500005][5];
//1 2 3(原来) 4 5
signed main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++) {
        scanf("%d",&a[i]);
        ma[a[i]]++;
    }
    for(int i=1;i<=m;i++) {
        scanf("%d",&b[i]);
        b[i+m]=b[i];
        t[b[i]][1]=i;
        t[b[i]][2]=i+m;
        ma[b[i]]++;
    } 
    int cnt=0,maxn=0;
    for(int i=1;i<=n;i++) if(!ma[i]) cnt++;
    for(int i=1;i<=m;i++) {
        int to=t[a[i]][1];
        if(!to) continue;
        if(sum[to-1]==i-1 || sum[to-1]==0) {
            maxn=max(maxn,pre[to-1]+1);
            pre[to]=pre[to-1]+1;
            sum[to]=i;
        } else {
            pre[to]=1;
            sum[to]=i;
        }
        to=t[a[i]][2];
        if(!to) continue;
        if(sum[to-1]==i-1 || sum[to-1]==0) {
            maxn=max(maxn,pre[to-1]+1);
            pre[to]=pre[to-1]+1;
            sum[to]=i;
        } else {
            pre[to]=1;
            sum[to]=i;
        }
    }
    memset(pre,0,sizeof pre);
    memset(sum,0,sizeof sum);
    for(int i=1;i<=m;i++) {
        int to=t[a[i]][1];
        if(!to) continue;
        if(sum[to+1]==i-1 || sum[to+1]==0) {
            maxn=max(maxn,pre[to+1]+1);
            pre[to]=pre[to+1]+1;
            sum[to]=i;
        } else {
            pre[to]=1;
            sum[to]=i;
        }
        to=t[a[i]][2];
        if(!to) continue;
        if(sum[to+1]==i-1 || sum[to+1]==0) {
            maxn=max(maxn,pre[to+1]+1);
            pre[to]=pre[to+1]+1;
            sum[to]=i;
        } else {
            pre[to]=1;
            sum[to]=i;
        }
    }
    printf("%d",maxn+cnt);
    return 0;
}
