#include<bits/stdc++.h>
using namespace std;
namespace IO{
    template<typename T>inline void read(T &x){
        x=0;int f=1;char c=getchar();
        while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
        while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
        x*=f;
    }
    const int BUF=1<<21;
    char buf[BUF],ctop,cstk[32];int plen;
    #define flush() fwrite(buf,1,plen,stdout),plen=0
    inline void pc(char c){
        buf[plen++]=c;
        if(plen==BUF) flush();
    }
    template<typename T>inline void print(T x){
        if(!x){pc(48);return;}
        if(x<0) x=~x+1,pc('-');
        while(x) cstk[++ctop]=48+x%10,x/=10;
        while(ctop) pc(cstk[ctop--]);
    }
}
using namespace IO;
const int N=2e6+5;
int n,a[N],m,Id[N],b[N],lim;
long long ans1,ans2;
struct Tree{int pre,suf,mv,mi;}t[N<<2],val;
inline Tree operator+(Tree x,Tree y){
    int s1=x.mv+y.suf,s2=x.pre+y.mv;
    return (Tree){x.pre+y.pre,x.suf+y.suf,
        min(s1,s2),s1<=s2?x.mi:y.mi};
}
#define mid ((l+r)>>1)
void build(int p,int l,int r){
    if(l==r){
        t[p]=val;t[p].mi=l;
        return;
    }
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    t[p]=t[2*p]+t[2*p+1];
}
void change(int p,int l,int r,int x,int op){
    if(l==r){
        if(op) swap(t[p].pre,t[p].suf);
        else t[p].mv=1<<30;
        if(op==2) t[p].mv=t[p].pre;
        return;
    }
    if(x<=mid) change(2*p,l,mid,x,op);
    else change(2*p+1,mid+1,r,x,op);
    t[p]=t[2*p]+t[2*p+1];
}
int main(){
    read(n),read(m);
    for(int i=1;i<=m;++i){
        read(a[i]),Id[a[i]]=i;
        for(int x=a[i];x<=n;x+=x&-x) ans1+=b[x];
        for(int x=a[i];x;x-=x&-x) ++b[x];
    }
    ans2=ans1;
    val=(Tree){1,0,1,-1};
    build(1,1,m);
    for(int i=1,lim=0;i<=n;++i){
        if(Id[i]){
            change(1,1,m,Id[i],1+(Id[i]>=lim));
            continue;
        }
        int val=min((lim==0)?t[1].suf:(1<<30),t[1].mv);
        ans1+=val;
        if(lim==0&&val==t[1].suf) lim=0;
        else{
            int k=t[1].mi;
            for(int j=lim;j<k;++j) if(j) change(1,1,m,j,0);
            lim=k;
        }
    }
    val=(Tree){0,-1,0,-1};
    build(1,1,m);
    for(int i=n,lim=0;i;--i){
        if(Id[i]){
            change(1,1,m,Id[i],1+(Id[i]>=lim));
            continue;
        }
        int val=min((lim==0)?t[1].suf:(1<<30),t[1].mv);
        ans2-=val;
        if(lim==0&&val==t[1].suf) lim=0;
        else{
            int k=t[1].mi;
            for(int j=lim;j<k;++j) if(j) change(1,1,m,j,0);
            lim=k;
        }
    }
    print(ans1),pc(' '),print(ans2+1ll*(n-m)*(n-m-1)/2),pc('\n');
    flush();
    return 0;
}
