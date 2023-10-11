#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
const int N=12050;
std::vector<int> vt[N];
struct Node {
    int up,down;
    int st,ed;
}t[N<<2];
struct SegmentTree {
 #define ls(x) (x<<1)
 #define rs(x) (x<<1|1)
 #define NodeSize(x) (t[x].ed-t[x].st+1)
    void build(int id,int l,int r) {
        t[id]=(Node){0,0,l,r};
        if(l==r) return;
        int mid=(l+r)>>1;
        build(ls(id),l,mid);
        build(rs(id),mid+1,r);
    }
    void modify_up(int id,int l,int r) {
        if(l>r) std::swap(l,r);
        if(l<=t[id].st&&t[id].ed<=r) {
            t[id].up=1;
            return;
        }
        int mid=(t[id].st+t[id].ed)>>1;
        if(l<=mid) modify_up(ls(id),l,r);
        if(mid<r) modify_up(rs(id),mid+1,r);
    }
    void modify_down(int id,int l,int r) {
        if(l>r) std::swap(l,r);
        if(l<=t[id].st&&t[id].ed<=r) {
            t[id].down=1;
            return;
        }
        int mid=(t[id].st+t[id].ed)>>1;
        if(l<=mid) modify_down(ls(id),l,r);
        if(mid<r) modify_down(rs(id),l,r);
    }
    int query_up(int id,int l,int r) {
        if(l>r) std::swap(l,r);
        if(t[id].up) return std::min(NodeSize(id),t[id].ed-l+1);
        if(t[id].st==t[id].ed) return t[id].up;
        int mid=(t[id].st+t[id].ed)>>1,res=0;
        if(l<=mid) res+=query_up(ls(id),l,r);
        if(mid<r) res+=query_up(rs(id),l,r);
        return res;
    }
    int query_down(int id,int l,int r) {
        if(l>r) std::swap(l,r);
        if(t[id].down) return std::min(NodeSize(id),t[id].ed-l+1);
        if(t[id].st==t[id].ed) return t[id].down;
        int mid=(t[id].st+t[id].ed)>>1,res=0;
        if(l<=mid) res+=query_down(ls(id),l,r);
        if(mid<r) res+=query_down(rs(id),l,r);
        return res;
    }
};
int depth[N],siz[N],son[N],fa[N];
int dfn[N],rnk[N],top[N],p;
void dfs1(int now,int pre) {
    depth[now]=depth[pre]+1;
    fa[now]=pre;
    siz[now]=1;
    son[now]=0;
    for(auto ed : vt[now]) {
        if(ed==pre) continue;
        dfs1(ed,now);
        siz[now]+=siz[ed];
        if(siz[ed]>siz[son[now]]) son[now]=ed;
    }
}
void dfs2(int now,int nowtop) {
    top[now]=nowtop;
    dfn[now]=++p;
    rnk[p]=now;
    if(!son[now]) return;
    dfs2(son[now],nowtop);
    for(auto ed : vt[now])
        if(ed!=fa[now]&&ed!=son[now]) dfs2(ed,ed);
}
int n;
struct TS {
    SegmentTree SEG;
    bool check(int st,int ed) {
        int cnt=0,length=0;
        while(top[st]!=top[ed]) {
            if(depth[top[st]]>=depth[top[ed]]) {
                if(SEG.query_down(1,dfn[st],dfn[top[st]])) return false;
                cnt+=SEG.query_up(1,dfn[st],dfn[top[st]]);
                length+=dfn[top[st]]-dfn[st]+1;
                st=fa[top[st]];
            }
            if(depth[top[st]]<depth[top[ed]]) {
                if(SEG.query_up(1,dfn[ed],dfn[top[ed]])) return false;
                cnt+=SEG.query_down(1,dfn[ed],dfn[top[ed]]);
                length+=dfn[top[ed]]-dfn[ed]+1;
                ed=fa[top[ed]];
            }
        }
        if(depth[st]>depth[ed]) {
            if(SEG.query_down(1,dfn[st],dfn[son[ed]])) return false;
            cnt+=SEG.query_up(1,dfn[st],dfn[son[ed]]);
            length+=dfn[ed]-dfn[st];
        }
        else if(depth[st]<depth[ed]) {
            if(SEG.query_up(1,dfn[ed],dfn[son[st]])) return false;
            cnt+=SEG.query_up(1,dfn[ed],dfn[son[st]]);
            length+=dfn[st]-dfn[ed];
        }
        if(cnt==length) return false;
        return true;
    }
    void modify(int st,int ed) {
        while(top[st]!=top[ed]) {
            if(depth[top[st]]>=depth[top[ed]]) {
                SEG.modify_up(1,dfn[st],dfn[top[st]]);
                st=fa[top[st]];
            }
            else {
                SEG.modify_down(1,dfn[ed],dfn[top[ed]]);
                ed=fa[top[ed]];
            }
        }
        if(depth[st]>depth[ed]) SEG.modify_up(1,dfn[st],son[dfn[ed]]);
        else if(depth[st]<depth[ed]) SEG.modify_down(1,dfn[ed],dfn[son[st]]);
    }
};
int T;
int main() {
     freopen("robot.in","r",stdin);
     freopen("robot.out","w",stdout);
    for(scanf("%d",&T);T--;) {
        bool flag=true;
        int n,q;
        p=0;
        scanf("%d",&n);
        TS tree;
        tree.SEG.build(1,1,n);
        for(int i=1;i<=n;i++) vt[i].clear();
        for(int i=1;i<=n-1;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            vt[u].emplace_back(v);
            vt[v].emplace_back(u);
        }
        dfs1(1,0);
        dfs2(1,1);
        for(scanf("%d",&q);q--;) {
            int u,v;
            scanf("%d%d",&u,&v);
            if(!tree.check(u,v)) flag=false;
            else tree.modify(u,v);
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
