#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,m;
int deg[N];
int to[N<<1],nxt[N<<1],head[N<<1],tot1;
int to1[N<<1],head1[N<<1],nxt1[N<<1],tot;
void add1(int u,int v){
    to1[++tot]=v,nxt1[tot]=head1[u],head1[u]=tot;
    to1[++tot]=u,nxt1[tot]=head1[v],head1[v]=tot;
}
void add(int u,int v){
    // if(typ) swap(u,v);
    to[++tot]=v,nxt[tot]=head[u],head[u]=tot;
    deg[v]++;
}
int f[N],son[N],rev[N],top[N],dfn[N],siz[N],dep[N],cntd;
void dfs(int u,int fa){
    dep[u]=dep[fa]+1,siz[u]=1,f[u]=fa;
    for(int i=head1[u];i;i=nxt1[i]){
        if(to1[i]==fa) continue;
        dfs(to1[i],u);
        siz[u]+=siz[to1[i]];
        if(siz[to1[i]]>siz[son[u]]) son[u]=to1[i];
    }
}
void dfs2(int u,int tp){
    top[rev[dfn[u]=++cntd]=u]=tp;
    if(son[u]) dfs2(son[u],tp);
    for(int i=head1[u];i;i=nxt1[i]) if(to1[i]^f[u]&&to1[i]^son[u]) dfs2(to1[i],to1[i]);
}
int cnt(0);
int leaf[N][2];
struct SMT{
    #define lc t[pos].ls
    #define rc t[pos].rs
    #define mid ((l+r)>>1)
    struct Node{
        int ls,rs;
    }t[N<<2];
    void build(int &pos,int l,int r,int typ){
        pos=++cnt;
        if(l==r) return leaf[l][typ]=pos,void();
        t[pos].ls=t[pos].rs=0;
        build(lc,l,mid,typ);build(rc,mid+1,r,typ);
        if(typ) add(pos,lc),add(pos,rc);
        else add(lc,pos),add(rc,pos);
    }
    void update(int pos,int l,int r,int L,int R,int x,int typ){
        if(r<L||R<l||R<L) return;
        if(L<=l&&r<=R) return typ?add(x,pos):add(pos,x),void();
        update(lc,l,mid,L,R,x,typ);
        update(rc,mid+1,r,L,R,x,typ);
    }
    #undef lc
    #undef rc
    #undef mid
}S,T;
int trt,srt;
void update(int x,int y,int z){
    if(dep[x]<dep[y]) swap(x,y);
    if(dfn[y]<=dfn[x]&&dfn[x]<=dfn[y]+siz[y]-1){
        x=f[x];
        while(top[x]^top[y]){
            S.update(srt,1,n,dfn[top[x]],dfn[x],z,0);
            T.update(trt,1,n,dfn[top[x]],dfn[x],z,1);
            x=f[top[x]];
        }
        S.update(srt,1,n,dfn[y]+1,dfn[x],z,0);
        T.update(trt,1,n,dfn[y]+1,dfn[x],z,1);
    }else{
        x=f[x],y=f[y];
        while(top[x]^top[y]){
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            S.update(srt,1,n,dfn[top[x]],dfn[x],z,0);
            T.update(trt,1,n,dfn[top[x]],dfn[x],z,1);
            x=f[top[x]];
        }
        if(dfn[x]<dfn[y]) swap(x,y);
        S.update(srt,1,n,dfn[y],dfn[x],z,0);
        T.update(trt,1,n,dfn[y],dfn[x],z,1);
    }
}
bool topo(){
    queue<int> q;
    for(int i=1;i<=cnt;i++) if(!deg[i]) q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nxt[i]){
            deg[to[i]]--;
            if(!deg[to[i]]) q.push(to[i]);
        }
    }
    for(int i=1;i<=cnt;i++) if(deg[i]) return false;
    return true;
}
void clear(){
    memset(head1,0,sizeof(int)*(n+1));
    memset(head,0,sizeof(int)*(cnt+1));
    memset(son,0,sizeof(int)*(n+1));
    memset(deg,0,sizeof(int)*(cnt+1));
    tot=tot1=cnt=cntd=srt=trt=0;
}
int main(){
     freopen("robot.in","r",stdin);
     freopen("robot.out","w",stdout);
    int t;cin>>t;
    while(t-->0){
        clear();
        scanf("%d",&n);
        for(int i=2,u,v;i<=n;i++){
            scanf("%d%d",&u,&v);
            add1(u,v);
        }
        dfs(1,0),dfs2(1,1);
        S.build(srt,1,n,0);
        T.build(trt,1,n,1);
        scanf("%d",&m);
        for(int i=1,s,t;i<=m;i++){
            scanf("%d%d",&s,&t);
            cnt++;
            add(leaf[dfn[t]][0],cnt),add(cnt,leaf[dfn[s]][0]);
            add(leaf[dfn[t]][1],cnt),add(cnt,leaf[dfn[s]][1]);
            update(s,t,cnt);
        }
        puts(topo()?"Yes":"No");
    }
}