#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
const int max_n=100005,Inf=1000000000;

int n,m,ok,a[max_n],b[max_n];

struct dot{
    int fa,son[2],val,sz,cnt,tg;
    dot(){fa=sz=cnt=val=son[0]=son[1]=tg=0;}
};
struct Splay{
    int tot;
    dot a[max_n];
    Splay(){tot=0;}
    #define root a[0].son[1]
    #define ls(x) (a[x].son[0])
    #define rs(x) (a[x].son[1])
    #define fa(x) (a[x].fa)
    inline bool getson(int x){
        return rs(fa(x))==x;
    }
    inline void connect(int u,int fa,int k){
        fa(u)=fa,
        a[fa].son[k]=u;
    }
    inline void pushup(int x){
        a[x].sz=a[ls(x)].sz+a[rs(x)].sz+a[x].cnt;
    }
    inline void pushdown(int u){
        if(!u || !a[u].tg) return;
        a[ls(u)].tg^=1,
        a[rs(u)].tg^=1;
        swap(ls(u),rs(u));
        a[u].tg=0;
    }
    inline void rotate(int x){
        int y=fa(x),z=fa(y),k=getson(x),p=getson(y);
        connect(a[x].son[k^1],y,k),
        connect(y,x,k^1),
        connect(x,z,p);
        pushup(y),pushup(x);
    }
    inline void splay(int x,int to){
        while(fa(x)!=to){
            int y=fa(x),z=fa(y),k=getson(x),p=getson(y);
            if(z==to) rotate(x);
            else if(k==p) rotate(y),rotate(x);
            else rotate(x),rotate(x);
        }
        if(!to) root=x;
    }
    inline int addnew(int val,int fa){
        a[++tot].fa=fa,
        a[tot].val=val,
        a[tot].cnt=a[tot].sz=1;
        return tot;
    }
    inline int build(int l,int r,int fa){
        int mid=(l+r)>>1,u=addnew(::a[mid],fa);
        if(l==r) return u;
        if(l<mid) ls(u)=build(l,mid-1,u);
        if(r>mid) rs(u)=build(mid+1,r,u);
        pushup(u);
        return u;
    }
    inline int kth(int x){
        int u=root;
        while(1){
            pushdown(u);
            int rank=a[u].sz-a[rs(u)].sz;
            if(x>a[ls(u)].sz && x<=rank) return u;
            if(x<rank) u=ls(u);
            else x-=rank,u=rs(u);
        }
    }
    inline void reverse(int l,int r){
        l=kth(l-1),r=kth(r+1);
        splay(l,0),splay(r,l);
        a[ls(rs(root))].tg^=1;
    }
    inline void ask(int u){
        pushdown(u);
        if(ls(u)) ask(ls(u));
        if(a[u].val>=1 && a[u].val<=n)
            b[++*b]=a[u].val;
        if(rs(u)) ask(rs(u));
    }
}spl;
inline void Reverse(int l,int r){
    spl.reverse(l+1,r+1);
}

inline void Clear(){
    for(int i=0;i<=spl.tot;++i)
        spl.a[i]=dot();
    spl.tot=0;
    for(int i=0;i<=n+2;++i)
        a[i]=b[i]=0;
}
inline int Check(){
    n=inf.readInt();
    m=ouf.readInt();
    ok=ans.readInt();
    a[1]=-Inf,a[n+2]=Inf;
    for(int i=1;i<=n;++i)
        a[i+1]=inf.readInt();
    if(m<-1 || m>300000)
        return 3;
    if(ok==-1){
        if(m==-1)
            return 0;
        else
            return 1;
    }
    if(m==-1)
        return 2;
    spl.root=spl.build(1,n+2,0);
    for(int i=1;i<=m;++i){
        int x=ouf.readInt();
        if(x<1 || x>n)
            return 4;
        if(x>1) Reverse(1,x-1);
        if(x<n) Reverse(x+1,n);
    }
    spl.ask(spl.root);
    for(int i=2;i<=n;++i) if(b[i]<b[i-1])
        return 5;
    return 0;
}

signed main(int argc,char *argv[]){
    registerTestlibCmd(argc,argv);
    int T=inf.readInt();
    for(int id=1;id<=T;++id){
        int res=Check();
        if(res!=0)
            quitf(_wa,"WA[%d] on %d",res,id);
        if(id<T) Clear();
    }
    quitf(_ok,"Accepted");
    return 0;
}
