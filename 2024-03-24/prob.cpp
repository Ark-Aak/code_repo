#include<bits/stdc++.h>
#define int long long
namespace IO{
    template<typename T>
    void read(T &x){
        char ch=getchar();int fl=1;x=0;
        while(ch>'9'||ch<'0'){if(ch=='-')fl=-1;ch=getchar();}
        while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
        x*=fl;
    }
    template<typename T,typename ...Args>
    void read(T &x,Args& ...args){
        read(x);read(args...);
    }
    template <typename _Tp>
    void write(_Tp x) {
        if(x<0) x=(~x+1),putchar('-');
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
using namespace std;
using namespace IO;
const int N=2e5+5,mod=998244353,K=10;
int n,Q,a[N],cnt=0;
vector<int> e[N];
vector<int> sop[N][K+5];
inline int inc(int x,int y) {return 1ll*x+y<mod?1ll*x+y:1ll*x+y-mod;}
inline int dec(int x,int y) {return x>y?1ll*x-y:1ll*x-y+mod;}
int dep[N],dfn[N],dfm[N],top[N],fa[N],siz[N],son[N],cntn,cntm;
int st[N][3],ed[N][3],smid[N],depf[N],id[N],Min[N][K+5],Max[N][K+5],dson[N][K+5],lst;
struct Sgt_Tree {
    #define ls ((x<<1))
    #define rs ((x<<1)|1)
    #define mid ((l+r)>>1)
    int sum[N<<2],mul[N<<2],laz[N<<2];
    void pushdown(int x) {
        sum[ls]=inc((1ll*sum[ls]*mul[x])%mod,laz[x]);
        sum[rs]=inc((1ll*sum[rs]*mul[x])%mod,laz[x]);
        mul[ls]=(1ll*mul[x]*mul[ls])%mod;
        mul[rs]=(1ll*mul[x]*mul[rs])%mod;
        laz[ls]=inc((1ll*mul[x]*laz[ls])%mod,laz[x]);
        laz[rs]=inc((1ll*mul[x]*laz[rs])%mod,laz[x]);
        mul[x]=1,laz[x]=0;
    }
    void build(int x,int l,int r) {
        mul[x]=1; laz[x]=0;
        if(l==r) {
            sum[x]=a[id[l]];
            return ;
        }
        build(ls,l,mid);
        build(rs,mid+1,r);
        sum[x]=inc(sum[ls],sum[rs]);
    }
    void modify(int x,int l,int r,int L,int R,int A,int B) {
        if(L>R || l>r) return ;
        if(L<=l && r<=R) {
            sum[x]=inc((1ll*sum[x]*A)%mod,B);
            mul[x]=(1ll*mul[x]*A)%mod;
            laz[x]=inc((1ll*laz[x]*A)%mod,B);
            return ;
        }
        pushdown(x);
        if(L<=mid) modify(ls,l,mid,L,R,A,B);
        if(mid<R) modify(rs,mid+1,r,L,R,A,B);
        sum[x]=inc(sum[ls],sum[rs]);
    }
    int query(int x,int l,int r,int pos) {
        int res=0;
        if(l==r) return sum[x];
        pushdown(x);
        if(pos<=mid) res=query(ls,l,mid,pos);
        if(mid<pos) res=query(rs,mid+1,r,pos);
        sum[x]=inc(sum[ls],sum[rs]);
        return res;
    }
}T;
void Makeson(int u,int op) {
    queue<pair<int,int> > Q; 
    Q.push({u,0});
    while(!Q.empty()) {
        int x=Q.front().first,y=Q.front().second;Q.pop();
        if(!op) sop[u][y].push_back(x);
        else if(depf[x]<K && x<=n) Min[u][y]=min(Min[u][y],dfn[x]),Max[u][y]=max(Min[u][y],dfn[x]);
        for(auto i:e[x]) {
            if(i==fa[x]) continue;
            if(y<=K) Q.push({i,y+1});
        }
    }
}
void dfs1(int x,int fe) {
    fa[x]=fe; siz[x]=1; dep[x]=dep[fe]+1;
    for(auto i:e[x]) {
        if(i==fe) continue;
        dfs1(i,x);
        siz[x]+=siz[i];
        if(siz[i]>siz[son[x]]) son[x]=i;
    }
}
void dfs2(int x,int topf,int len) {
    Makeson(x,0);
    depf[x]=len-1;
    if(x<=n) st[x][0]=cntn+1;
    if(len>K && x<=n) dfn[x]=++cntn;
    if(son[x]) {
        int u=son[x],l=0;
        while(l<=K) {
            dson[u][l]=son[x];
            if(u==topf) break;
            u=fa[u]; l++;
        }
        dfs2(son[x],topf,len+1);
    }
    for(auto i:e[x]) {
        if(i==fa[x] || i==son[x]) continue;
        dfs2(i,i,1);
    }
    if(x<=n) ed[x][0]=cntn;
} 
void dfs3(int x) {
    for(auto i:sop[x][K]) if(depf[i]<K) dfn[i]=++cntn;
    if(x<=n) st[x][1]=cntn+1;
    if(son[x]) dfs3(son[x]);
    for(auto i:e[x]) {
        if(i==fa[x] || i==son[x]) continue;
        dfs3(i);
    }
    if(x<=n) ed[x][1]=cntn;
}
void dfs4(int x,int topf) {
    if(dfn[x]<=lst) top[x]=topf;
    else top[x]=x;
    if(son[x]) {
        if(dfn[son[x]]<=lst && dfn[topf]>lst) dfs4(son[x],son[x]);
        else dfs4(son[x],topf);
    }
    for(auto i:e[x]) if(i==fa[x] || i==son[x]) dfs4(i,i);
}
void Modifylist(int x,int y,int A,int B) {
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		T.modify(1,1,n,dfn[top[x]],dfn[x],A,B);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	T.modify(1,1,n,dfn[x],dfn[y],A,B);
}
void Modifyaround(int x,int k,int A,int B) {
    for(int i=0;i<=k;i++) {
        T.modify(1,1,n,Min[x][k-i],Max[x][k-i],A,B); 
        if(depf[dson[x][k-i]]>=K && dfn[dson[x][k-i]]) {
            T.modify(1,1,n,dfn[dson[x][k-i]],dfn[dson[x][k-i]],A,B);
        }
        if(i<k) {
            T.modify(1,1,n,Min[x][k-i-1],Max[x][k-i-1],A,B);
            if(depf[dson[x][k-i-1]]>=K && dfn[dson[x][k-i-1]]) {
                T.modify(1,1,n,dfn[dson[x][k-i-1]],dfn[dson[x][k-i-1]],A,B);
            }
        }
        x=fa[x]; 
    }
}
void Modifyson(int x,int A,int B) {
    T.modify(1,1,n,st[x][0],ed[x][0],A,B);
    for(int i=0;i<=K;i++) T.modify(1,1,n,Min[x][i],Max[x][i],A,B);
    T.modify(1,1,n,st[x][1],ed[x][1],A,B);
}
signed main() {
    // freopen("tree.in","r",stdin);
    // freopen("tree.out","w",stdout);
    read(n,Q);
    for(int i=1;i<n;i++) {
        int x,y;
        read(x,y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    memset(Min,0x3f,sizeof Min);
    for(int i=1;i<=n;i++) read(a[i]);
    int now=1;
    for(int i=1;i<=K;i++) {
        e[n+i].push_back(now);
        e[now].push_back(n+i);
        now=n+i;
    }
    dfs1(now,0);
    dfs2(now,now,1);lst=cntn;
    dfs3(now);
    for(int i=1;i<=n;i++) id[dfn[i]]=i;
    for(int i=1;i<=n+K;i++) Makeson(i,1);
    T.build(1,1,n);
    while(Q--) {
        int op;
        read(op);
        if(op==1) {
            int u;
            read(u);
            write(T.query(1,1,n,dfn[u])); putchar('\n');
        } else if(op==2) {
            int u,k,A,B;
            read(u,k,A,B);
            Modifyaround(u,k,A,B);
        } else if(op==3) {
            int u,A,B;
            read(u,A,B);
            Modifyson(u,A,B);
        } else {
            int u,v,A,B;
            read(u,v,A,B);
            Modifylist(u,v,A,B);
        }
    }
    return 0;
}
/*

*/

