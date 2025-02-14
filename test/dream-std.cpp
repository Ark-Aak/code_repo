#include<bits/stdc++.h>
#define ll long long
char buf[1 << 20], *p1, *p2;
#define getchar()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
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
const int N=1e6+5,mod=998244353,inv2=(mod+1)/2;
inline int Inc(int x,int y) {return x+y<mod?x+y:x+y-mod;}
inline int Dec(int x,int y) {return x>=y?x-y:x-y+mod;}
inline int Mul(int x,int y) {return (1ll*x*y)%mod;}
int n,m,q,IDcnt,lcnt=0,fa[N],a[N],Num[N];
ll num;
struct Ques {ll op,l,r,k;}Q[N];
#include <bits/extc++.h>
__gnu_pbds::cc_hash_table <ll,int> ma,listma;
const int MOD = (1 << 19) - 1;

struct hashtable {

    list <pair <long long, int> > buc[MOD + 1];

    int& operator[](long long key) {
        const int pos = key & MOD;
        for (auto &[x, y] : buc[pos]) {
            if (x == key) return y;
        }
        buc[pos].emplace_back(key, 0);
        return buc[pos].back().second;
    }
//} ma, listma;
};
vector<int> e[N];
vector<ll> S[N];
set<ll> Sp;
void InsertNode(ll x) {
    if(ma[x] == 0) ma[x]=++IDcnt;
    else return ;
    Num[ma[x]]=1;
    ll p=*(Sp.lower_bound(x));
    S[listma[p]].push_back(x);
}
int dfn[N],siz[N],dep[N],son[N],top[N],cnt,dfc[N],szz[N];
void dfs1(int x) {
    siz[x]=1; szz[x]=(x<=n);
    dep[x]=dep[fa[x]]+1;
    for(auto i:e[x]) {
        dfs1(i);siz[x]+=siz[i];szz[x]+=szz[i];
        if(siz[son[x]]<siz[i]) son[x]=i;
    }
}
void dfs2(int x,int topf) {
    top[x]=topf;
    dfn[x]=++cnt; dfc[cnt]=x;
    if(son[x]) dfs2(son[x],topf);
    else return;
    for(auto i:e[x]) {
        if(i==son[x]) continue;
        dfs2(i,i);
    }
}
struct SGT {
    #define ls ((x<<1))
    #define rs ((x<<1)|1)
    #define mid ((l+r)>>1)
    int sum[N<<2],num[N<<2],laz1[N<<2],laz2[N<<2];
    inline int calc(int x) {
        return ((1ll*(x+1)*x) >> 1)%mod;
    }
    void build(int x,int l,int r) {
        if(l==r) {
            sum[x]=szz[dfc[l]];
            num[x]=Num[dfc[l]];
            return ;
        }
        build(ls,l,mid); build(rs,mid+1,r);
        pushup(x);
    }
    inline void pushup(int x) {
        sum[x]=Inc(sum[ls],sum[rs]);
        num[x]=Inc(num[ls],num[rs]);
    }
    inline void pushdown(int x) {
        if(laz1[x]) {
            laz1[ls]=Inc(laz1[ls],laz1[x]);
            laz1[rs]=Inc(laz1[rs],laz1[x]);
            sum[rs]=Inc(sum[rs],Mul(calc(num[rs]),laz1[x]));
            sum[ls]=Inc(sum[ls],Mul(num[ls],Mul(num[rs],laz1[x])));
            laz2[ls]=Inc(laz2[ls],Mul(num[rs],laz1[x]));
            sum[ls]=Inc(sum[ls],Mul(calc(num[ls]),laz1[x]));
            laz1[x]=0;
        }
        if(laz2[x]) {
            laz2[ls]=Inc(laz2[ls],laz2[x]);
            laz2[rs]=Inc(laz2[rs],laz2[x]);
            sum[ls]=Inc(sum[ls],Mul(num[ls],laz2[x]));
            sum[rs]=Inc(sum[rs],Mul(num[rs],laz2[x]));
            laz2[x]=0;
        }
    }
    int Inum=0;
    void modify1(int x,int l,int r,int L,int R,int p) {
    	if(p==0) return;
        if(L<=l && r<=R) {
            sum[x]=Inc(sum[x],Inc(Mul(Mul(Inum,p),num[x]),Mul(calc(num[x]),p)));
            laz1[x]=Inc(laz1[x],p);
            laz2[x]=Inc(laz2[x],Mul(Inum,p));
            Inum=Inc(Inum,num[x]);
            return ;
        }
        if(laz1[x] || laz2[x]) pushdown(x);
        if(mid<R) modify1(rs,mid+1,r,L,R,p);
        if(L<=mid) modify1(ls,l,mid,L,R,p);
        pushup(x);
    }
    void modify2(int x,int l,int r,int L,int R,int k) {
    	if(k==0) return;
        if(L<=l && r<=R) {
            sum[x]=Inc(sum[x],Mul(num[x],k));
            laz2[x]=Inc(laz2[x],k);
            return ;
        }
        if(laz1[x] || laz2[x]) pushdown(x);
        if(L<=mid) modify2(ls,l,mid,L,R,k);
        if(mid<R) modify2(rs,mid+1,r,L,R,k);
        pushup(x);
    }
    int query1(int x,int l,int r,int L,int R) {
        if(L<=l && r<=R) return sum[x];
        if(laz1[x] || laz2[x]) pushdown(x);
        int res=0;
        if(L<=mid) res=Inc(res,query1(ls,l,mid,L,R));
        if(mid<R) res=Inc(res,query1(rs,mid+1,r,L,R));
        return res;
    }
}T;
inline int lca(int x,int y) {
    while(top[x]!=top[y]) {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
inline void update(int x,int y,int k) {
	if(k==0) return;
    int res=0,l=lca(x,y);
    T.Inum=0;
    while(top[x]^top[l]) {
        T.modify1(1,1,IDcnt,dfn[top[x]],dfn[x],k);
        x=fa[top[x]];
    }
    T.modify1(1,1,IDcnt,dfn[l],dfn[x],k);
    res=Inc(res,T.Inum);T.Inum=0;
    while(top[y]^top[l]) {
        T.modify1(1,1,IDcnt,dfn[top[y]],dfn[y],k);
        y=fa[top[y]];
    }
    T.modify1(1,1,IDcnt,dfn[l],dfn[y],k);
    res=Inc(res,T.Inum); res=Dec(res,Num[l]);
    T.modify2(1,1,IDcnt,dfn[l],dfn[l],Dec(0,k)); l=fa[l];
    while(l) {
        T.modify2(1,1,IDcnt,dfn[top[l]],dfn[l],Mul(res,k));
        l=fa[top[l]];
    }
}
inline void update2(int x) {
    while(x) {
        T.modify2(1,1,IDcnt,dfn[top[x]],dfn[x],1);
        x=fa[top[x]];
    }
}
inline int query(int x,int y) {
    int res=0;
    while(top[x]^top[y]) {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        res=Inc(res,T.query1(1,1,IDcnt,dfn[top[x]],dfn[x]));
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    res=Inc(res,T.query1(1,1,IDcnt,dfn[x],dfn[y]));
    return res;
}
inline void Add(int x,int y) {
    fa[y]=x;
    e[x].push_back(y);
}
signed main() {
    read(n,q);
    ma[1]=1;a[1]=1;Num[1]=1;
    for(int i=2;i<=n;i++) {
        read(fa[i]);
        ma[i]=i;a[i]=1;Num[i]=1;
        Add(fa[i],i);
    }
    num=n;IDcnt=n;
    for(int i=1;i<=q;i++) {
        read(Q[i].op,Q[i].l,Q[i].r);
        if(Q[i].op==1) {
            read(Q[i].k);
            InsertNode(Q[i].l);
            InsertNode(Q[i].r);
        } else if(Q[i].op==2) {
            listma[num+Q[i].r]=++lcnt;
            Sp.insert(num+Q[i].r);
            S[lcnt].push_back(num+1);
            InsertNode(Q[i].l);
            InsertNode(num+1);
            fa[ma[num+1]]=ma[Q[i].l];
            Add(ma[Q[i].l],ma[num+1]);
            if(Q[i].r>1) {
                InsertNode(num+Q[i].r);
                S[lcnt].push_back(num+Q[i].r);
            }
            num+=Q[i].r;
        } else {
            InsertNode(Q[i].l);
            InsertNode(Q[i].r);
        }
    }
    for(int i=1;i<=lcnt;i++) {
        ll lst=0;
        sort(S[i].begin(),S[i].end());
        for(auto j:S[i]) {
            if(fa[ma[j]]) {lst=j;continue;}
            if((j-lst-1)==0) Add(ma[lst],ma[j]);
            else {
                IDcnt++; Num[IDcnt]=Mul((j-lst-1),1);
                Add(ma[lst],IDcnt); Add(IDcnt,ma[j]);
            }
            lst=j;
        }
    }
    dfs1(1); dfs2(1,1);
    T.build(1,1,IDcnt);
    num=n;
    for(int i=1;i<=q;i++) {
        if(Q[i].op==1) {
			// continue;
			update(ma[Q[i].l],ma[Q[i].r],Mul(Q[i].k,1));
		}
        else if(Q[i].op==2) update(ma[num+1],ma[num+Q[i].r],1),num+=Q[i].r;
        else write(query(ma[Q[i].l],ma[Q[i].r])),putchar('\n');
    }
    return 0;
}
