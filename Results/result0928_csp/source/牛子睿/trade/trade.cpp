#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
int c;
struct node {
    int now,step,point;
    int val(void){return c*(point-step*step);}
};
const int N=1005;
std::queue<node> q;
std::vector<int> vt[N],change[N];
int n,m,ans,dis[N],val[N];
bool vis[N];
void dfs(int now) {
    vis[now]=true;
    for(auto ed:vt[now])
        if(!vis[ed]) dfs(ed);
}
int main() {
    freopen("trade.in","r",stdin);
    freopen("trade.out","w",stdout);
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++) scanf("%d",&val[i]);
    for(int i=1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        vt[u].emplace_back(v);
        change[v].emplace_back(u);
    }
    dfs(1);
    q.push((node){1,0,0});
    while(!q.empty()) {
        auto u=q.front();
        q.pop();
        if(u.now==1) ans=std::max(ans,u.val());
        for(auto ed:vt[u.now]) {
            if(!vis[ed]) continue;
            node expand_=(node){ed,u.step+1,u.point+val[ed]};
            if(dis[ed]<expand_.val()) {
                dis[ed]=expand_.val();
                q.push(expand_);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
