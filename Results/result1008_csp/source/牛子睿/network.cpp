#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
const int N=4050;
int depth[N],siz[N],son[N],fa[N];
int top[N],dfn[N],rnk[N],cnt;
int min[N][N];
std::vector<int> vt[N];
std::vector<int> visited;
int getmin(int x,int y) {
    return min[std::min(x,y)][std::max(x,y)];
}
void dfs1(int now,int pre) {
    depth[now]=depth[pre]+1;
    fa[now]=pre;
    siz[now]=1;
    for(auto ed : vt[now]) {
        if(ed==pre) continue;
        dfs1(ed,now);
        siz[now]+=siz[ed];
        if(siz[ed]>siz[son[now]]) son[now]=ed;
    }
}
void dfs2(int now,int nowtop) {
    dfn[now]=++cnt;
    rnk[cnt]=now;
    top[now]=nowtop;
    if(!son[now]) return;
    dfs2(son[now],nowtop);
    for(auto ed : vt[now])
        if(ed!=son[now]&&fa[now]!=ed) dfs2(ed,ed);
}
struct TS {
    int query(int x,int y) {
        int res=0x3f3f3f3f;
        while(top[x]!=top[y]) {
            if(depth[top[x]]<depth[top[y]]) std::swap(x,y);
            res=std::min(res,getmin(dfn[x],dfn[top[x]]));
            x=fa[top[x]];
        }
        res=std::min(res,getmin(dfn[x],dfn[y]));
        return res;
    }
};
int n,q;
signed main() {
    freopen("network.in","r",stdin);
    freopen("network.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n-1;i++) {
        int u,v;
        scanf("%lld%lld",&u,&v);
        vt[u].emplace_back(v);
        vt[v].emplace_back(u);
    }
    dfs1(1,0);
    dfs2(1,1);
    for(int i=1;i<=n;i++) {
        int nowmin=0x3f3f3f3f;
        for(int j=i;j<=n;j++) {
            nowmin=std::min(rnk[j],nowmin);
            min[i][j]=nowmin;
        }
    }
    TS tree;
    while(q--) {
        char opt[114];
        int x,res=0x3f3f3f3f;
        scanf("%s%lld%lld",&opt,&x);
        if(opt[0]=='J') visited.emplace_back(x);
        if(opt[0]=='Q') {
            for(auto i : visited) 
                res=std::min(res,tree.query(x,i));
            printf("%d\n",res);
        }
    }
    return 0;
}