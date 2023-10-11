#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define mkp std::make_pair
const int N=50050;
const int K=55;
std::vector< std::pair<int,int> > vt[N];
std::priority_queue< std::pair<int,int> > q;
int pre[N][K],nxt[N][K];
bool vis[N];
int dis[N];
int c[N];
int n,k;
int main() {
    freopen("tower.in","r",stdin);
    freopen("tower.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++)
            pre[i][j]=pre[i-1][j];
        pre[i][c[i-1]]=i-1;
    }
    for(int i=n;i>=1;i--) {
        for(int j=1;j<=k;j++)
            nxt[i][j]=nxt[i+1][j];
        nxt[i][c[i+1]]=i+1;
    }
    for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++) {
            int tmp;
            scanf("%1d",&tmp);
            if(tmp==1)
                for(int t=1;t<=n;t++)
                    if(c[t]==i) {
                        if(pre[t][j]) vt[t].push_back(mkp(t-pre[t][j],pre[t][j]));
                        if(nxt[t][j]) vt[t].push_back(mkp(nxt[t][j]-t,nxt[t][j]));
                    }
        }
    q.push(mkp(0,1));
    dis[1]=0;
    while(!q.empty()) {
        int now=q.top().second;
        q.pop();
        if(vis[now]) continue;
        vis[now]=true;
        for(auto i : vt[now]) {
            int val=i.first,ed=i.second;
            if(dis[ed]>dis[now]+val) {
                dis[ed]=dis[now]+val;
                q.push(mkp(-dis[ed],ed));
            }
        }
    }
    printf("%d",dis[n]);
    return 0;
}