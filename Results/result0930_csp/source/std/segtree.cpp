#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

namespace IOR{
	char ib[1<<22],ob[1<<20],*p1=ib,*p2=ib,*po=ob;
	void flush(){fwrite(ob,sizeof(char),po-ob,stdout);po=ob;}struct OC{~OC(){flush();};}Oc;
	char gc(){return p1==p2&&(p2=(p1=ib)+fread(ib,sizeof(char),sizeof(ib),stdin),p1==p2)?EOF:*p1++;}
	void pc(const char c){*po++=c;if(po-ob==sizeof(ob))flush();}
	void pt(const char *s){while(*s!='\0'){pc(*s);s++;}pc('\n');}
}
#define getchar IOR::gc
#define putchar IOR::pc
#define puts IOR::pt

namespace fastio{
    struct{template<typename T>operator T(){
        T x=0;char f=0,c=getchar();
        while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
        while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
        return f?-x:x;
    }}in;int stk[40],tp;
    template<typename T>void out(T x,char c=0){
        if(x<0)putchar('-'),x=-x;
        do stk[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(stk[tp--]^48);
        if(c)putchar(c);
    }
}using fastio::in;using fastio::out;

typedef unsigned int uint;
const int N = 100005,M = 1000005,B1 = 384,B2 = 5760,L1 = N/B1+5,L2 = N/B2+5;
int p[N],rp[N],a[N],c[N];
uint ans[M],b[N];
int n,m;
class D2Block{
    private:
        int b1[N],b2[N],l1[L1],l2[L2];
        int p[N],rp[N];
        uint s1[L2][L2],s2[L1][L2],s3[L2][L1],s4[L1][L1],s5[N],s6[N];
        uint a[N],s[L1];
    public:
        D2Block(){
            for(int k=1;k<N;k++){
                b1[k] = (k-1)/B1;
                b2[k] = (k-1)/B2;
            }
            for(int k=0;k<L1;k++)
                l1[k] = k*B1+1;
            for(int k=0;k<L2&&k*B2+1<N;k++)
                l2[k] = b1[k*B2+1];
        }
        void add(int x,int y,int v){
            if(!y){
                s[b1[x]] += v;
                a[x] += v;
                return;
            }
            int x1 = b1[x],x2 = b2[x],y1 = b1[y],y2 = b2[y];
            s1[x2][y2] += v;
            s2[x1][y2] += v;
            s3[x2][y1] += v;
            s4[x1][y1] += v;
            s5[x] += v;
            s6[y] += v;
            p[x] = y,rp[y] = x;
        }
        uint query(int x,int y){
            if(!x)
                return 0;
            uint ans = 0;
            int x1 = b1[x],x2 = b2[x],y1 = b1[y],y2 = b2[y];
		    int qx = l1[x1],px = l2[x2],qy = l1[y1],py = l2[y2];
            for(int k=0;k<x2;k++)
                for(int j=0;j<y2;j++)
                    ans += s1[k][j];
            for(int k=px;k<x1;k++)
                for(int j=0;j<y2;j++)
                    ans += s2[k][j];
            for(int k=0;k<x2;k++)
                for(int j=py;j<y1;j++)
                    ans += s3[k][j];
            for(int k=px;k<x1;k++)
                for(int j=py;j<y1;j++)
                    ans += s4[k][j];
            for(int k=qx;k<=x;k++)
                if(p[k]<=y)
                    ans += s5[k];
            for(int k=qy;k<=y;k++)
                if(rp[k]<qx)
                    ans += s6[k];
            for(int k=0;k<x1;k++)
                ans += s[k];
            for(int k=qx;k<=x;k++)
                ans += a[k];
            return ans;
        }
        void clear(){
            memset(s1,0,sizeof(s1));
            memset(s2,0,sizeof(s2));
            memset(s3,0,sizeof(s3));
            memset(s4,0,sizeof(s4));
            memset(s5,0,sizeof(s5));
            memset(s6,0,sizeof(s6));
            memset(a,0,sizeof(a));
            memset(s,0,sizeof(s));
        }
}ds;

class inquiry{
    public:
        int l1,r1,l2,r2,block,id;
        bool operator < (const inquiry &tmp)const{
            if(block!=tmp.block)
                return l1<tmp.l1;
            return r1>tmp.r1;
        }
};

int pre[N],nxt[N],las[N];

void del(int u){
    if(nxt[u]){
        ds.add(nxt[u],u,-b[c[nxt[u]]]);
        pre[nxt[u]] = pre[u];
    }
    ds.add(u,pre[u],-b[c[u]]);
    if(pre[u])
        nxt[pre[u]] = nxt[u];
    if(nxt[u])
        ds.add(nxt[u],pre[u],b[c[nxt[u]]]);
}

int main(){
	freopen("segtree.in","r",stdin);
	freopen("segtree.out","w",stdout);
    n = in,m = in;
    for(int k=1;k<=n;k++)
        rp[p[k] = in] = k;
    for(int k=1;k<=n;k++)
        c[p[k]] = a[k] = in;
    for(int k=1;k<=n;k++)
        b[k] = in;
    vector<inquiry> q(m);
    int block = ceil((n-1)/sqrt(m));
    for(int k=0;k<m;k++){
        q[k].l1 = in,q[k].l2 = in,q[k].r1 = in,q[k].r2 = in;
        q[k].block = (q[k].l1-1)/block,q[k].id = k;
    }
    sort(q.begin(),q.end());
    int L,R,lbid = -1;
    auto init = [&L,&R,&block](int x){
        memset(pre,0,sizeof(pre));
        memset(nxt,0,sizeof(nxt));
        memset(las,0,sizeof(las));
        ds.clear();
        for(int k=1;k<=n;k++)
            if(rp[k]>=x){
                nxt[las[c[k]]] = k;
                pre[k] = las[c[k]];
                las[c[k]] = k;
            }
        L = x,R = n;
        for(int k=L;k<=R;k++)
            ds.add(p[k],pre[p[k]],b[a[k]]);
    };
    for(auto[l,r,l2,r2,bid,id]:q){
        if(lbid!=bid)
            init((lbid=bid)*block+1);
        while(R>r)
            del(p[R--]);
        while(L<l)
            del(p[L++]);
        ans[id] = ds.query(r2,l2-1)-ds.query(l2-1,l2-1);
        while(L>bid*block+1){
            int u = p[--L];
            if(nxt[u]){
                ds.add(nxt[u],pre[nxt[u]],-b[c[nxt[u]]]);
                pre[nxt[u]] = u;
            }
            ds.add(u,pre[u],b[c[u]]);
            if(pre[u])
                nxt[pre[u]] = u;
            if(nxt[u])
                ds.add(nxt[u],pre[nxt[u]],b[c[nxt[u]]]);
        }
    }
    for(int k=0;k<m;k++)
        out(ans[k],'\n');
    return 0;
}
