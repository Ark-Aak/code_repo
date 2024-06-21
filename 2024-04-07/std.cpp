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
const int N=5e6+5,mod=1e9+7;

int n,m,q;

inline int inc(int x,int y) {return 1ll*x+y<mod?1ll*x+y:1ll*x+y-mod;}
inline int dec(int x,int y) {return x>y?1ll*x-y:1ll*x-y+mod;}
inline int Mul(int x,int y) {return (x*y)%mod;}
namespace FHQ {
    #define ls ((ch[x][0]))
    #define rs ((ch[x][1]))

    int val[N],sum[N],Asiz[N],key[N],ch[N][2],laz[N],siz[N],tot,rt[N];

    int newnode(int v,int len){
        val[++tot]=v; sum[tot]=Mul(v,len);
        Asiz[tot]=len; siz[tot]=len;
        key[tot]=rand();
        return tot;
    }

    void pushup(int x) {
        Asiz[x]=siz[x]+Asiz[ls]+Asiz[rs];
        sum[x]=inc(inc(Mul(val[x],siz[x]),sum[ls]),sum[rs]);
    }

    void insert(int x,int v) {
        sum[x]=inc(sum[x],Mul(v,Asiz[x]));
        val[x]=inc(val[x],v);
        laz[x]=inc(laz[x],v);
    }

    void pushdown(int x) {
        if(ls) {
            sum[ls]=inc(sum[ls],Mul(Asiz[ls],laz[x]));
            val[ls]=inc(val[ls],laz[x]);
            laz[ls]=inc(laz[ls],laz[x]);
        }
        if(rs) {
            sum[rs]=inc(sum[rs],Mul(Asiz[rs],laz[x]));
            val[rs]=inc(val[rs],laz[x]);
            laz[rs]=inc(laz[rs],laz[x]);
        }
        laz[x]=0;
    }

    int merge(int x,int y) {
        pushdown(x); pushdown(y);
        if(!x || !y)return x + y;
        if(key[x]<key[y]) {
            ch[x][1] = merge(ch[x][1],y);
            pushup(x);
            return x;
        } else {
            ch[y][0] = merge(x,ch[y][0]);
            pushup(y);
            return y;
        }
    }

    void cut(int now,int k,int &x,int &y) {
		assert(siz[now]>=k);
        int lx=ch[now][0],rx=ch[now][1];
        ch[now][0]=ch[now][1]=0;
        int w=newnode(val[now],k); siz[now]-=k;
        pushup(now); pushup(w);
        x=merge(lx,w); y=merge(now,rx);
    }

	void split(int now,int k,int &x,int &y) {
		if(!now) {x=y=0;return ;}
		pushdown(now);
		if(Asiz[ch[now][0]]+siz[now]<=k) {
			x=now;
			split(ch[now][1],k-Asiz[ch[now][0]]-siz[now],ch[now][1],y);
            pushup(now);
		} else if(Asiz[ch[now][0]]>=k){
			y=now;
			split(ch[now][0],k,x,ch[now][0]);
            pushup(now);
		} else cut(now,k-Asiz[ch[now][0]],x,y);
	}

    #undef ls
    #undef rs
}

struct SgtTree {
    #define rs ((x<<1)|1)
    #define ls ((x<<1))
    #define mid ((l+r)>>1)
    int sum[N<<2],len[N<<2],laz[N<<2];

    void build(int x,int l,int r) {
        len[x]=n;
        if(l==r) return ;
        build(ls,l,mid); build(rs,mid+1,r);
        len[x]=inc(len[ls],len[rs]);
    }
    void pushdown(int x) {
        sum[ls]=inc(sum[ls],Mul(laz[x],len[ls]));
        sum[rs]=inc(sum[rs],Mul(laz[x],len[rs]));
        laz[ls]=inc(laz[ls],laz[x]); laz[rs]=inc(laz[rs],laz[x]);
        laz[x]=0;
    }

    void modify(int x,int l,int r,int L,int R,int k,int op) {
        if(L<=l && r<=R) {
            if(!op) sum[x]=((sum[x]+k)%mod+mod)%mod;
            else if(op==1) {
                sum[x]=inc(sum[x],Mul(len[x],k));
                laz[x]=inc(laz[x],k);
            } else if(op==2) len[x]=(inc(len[x],k)+mod)%mod;
            return ;
        }
        if(laz[x]) pushdown(x);
        if(L<=mid) modify(ls,l,mid,L,R,k,op);
        if(mid<R) modify(rs,mid+1,r,L,R,k,op);
        sum[x]=inc(sum[ls],sum[rs]);
        len[x]=inc(len[ls],len[rs]);
    }

    int query(int x,int l,int r,int L,int R,int op) {
        int res=0;
        if(L<=l && r<=R) {
            if(!op) return sum[x];
            else {
                int res=laz[x];
                laz[x]=0;
                return res;
            }
        }
        if(laz[x]) pushdown(x);
        if(L<=mid) res=inc(res,query(ls,l,mid,L,R,op));
        if(mid<R) res=inc(res,query(rs,mid+1,r,L,R,op));
        sum[x]=inc(sum[ls],sum[rs]);
        return res;
    }

}T;

void Solops1(int p,int l,int r,int v) {
    int x,y,z;
    FHQ::split(FHQ::rt[p],r,y,z);
    FHQ::split(y,l-1,x,y); FHQ::insert(y,v);
    T.modify(1,1,m,p,p,Mul((r-l+1),v),0);
    FHQ::rt[p]=FHQ::merge(FHQ::merge(x,y),z);

}

void Solops2(int p,int l,int r) {
    int x,y,z;
    int res=T.query(1,1,m,p,p,1);
    FHQ::insert(FHQ::rt[p],res);
    FHQ::split(FHQ::rt[p],r,y,z);
    FHQ::split(y,l-1,x,y);
    write(FHQ::sum[y]); putchar('\n');
    FHQ::rt[p]=FHQ::merge(x,FHQ::merge(y,z));
}

void Solops3(int l,int r) {
    write(T.query(1,1,m,l,r,0));
    putchar('\n');
}

void Solops4(int l,int r,int v) {
    T.modify(1,1,m,l,r,v,1);
}

void Solops5(int p1,int l,int r,int p2,int t) {
    int x,y,z;

    int res=T.query(1,1,m,p1,p1,1);
    FHQ::insert(FHQ::rt[p1],res);
    FHQ::split(FHQ::rt[p1],r,y,z);
    FHQ::split(y,l-1,x,y); FHQ::rt[p1]=FHQ::merge(x,z);
    T.modify(1,1,m,p1,p1,-(r-l+1),2);
    T.modify(1,1,m,p1,p1,-FHQ::sum[y],0);
    T.modify(1,1,m,p2,p2,FHQ::sum[y],0);

    res=T.query(1,1,m,p2,p2,1);
    FHQ::insert(FHQ::rt[p2],res);
    FHQ::split(FHQ::rt[p2],t,x,z);
    FHQ::rt[p2]=FHQ::merge(x,FHQ::merge(y,z));
    T.modify(1,1,m,p2,p2,(r-l+1),2);
}
signed main() {
#ifdef LOCAL
    freopen("test.in","r",stdin);
#endif
    srand(time(0));
    read(n,m,q);
    T.build(1,1,m);
    for(int i=1;i<=m;i++) FHQ::rt[i]=FHQ::newnode(0,n);
    while(q--) {
        int ops;
        read(ops);
        if(ops==1) {
            int x,l,r,v;
            read(x,l,r,v);
            Solops1(x,l,r,v);
        } else if(ops==2) {
            int x,l,r;
            read(x,l,r);
            Solops2(x,l,r);
        } else if(ops==3) {
            int l,r;
            read(l,r);
            Solops3(l,r);
        } else if(ops==4) {
            int l,r,v;
            read(l,r,v);
            Solops4(l,r,v);
        } else if(ops==5) {
            int x,l,r,y,t;
            read(x,l,r,y,t);
            Solops5(x,l,r,y,t);
        }
    }
    return 0;
}
