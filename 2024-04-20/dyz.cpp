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
const int N=2e5+5,M=505,mod=1e9+7,base=998244353;
int n,q,a[N],len,tot;
int L[M],R[M],id[N],fac[N],inv[N],lg[N];
int sumHash[M][M],sumFact[M][M] ;
int preB[M],preSB[M][N];
int ksm(int x,int y) {
    int ans=1;
    while(y) {
        if(y&1) ans=(1ll*ans*x)%mod;
        x=(1ll*x*x)%mod; y>>=1;
    }
    return ans;
}
__int128 mu;
inline long long reduce(__int128 x) {
	__int128 r=x-(mu*x>>64)*mod;
	return r;
}
inline int Inc(int x,int y) {return x+y<mod?x+y:x+y-mod;}
inline int Dec(int x,int y) {return x>=y?x-y:x-y+mod;}
inline int Mul(int x,int y) {return (1ll*x*y)%mod;}
inline int Pos(int x,int k) {return Mul(a[x],fac[x%k]);}
inline void init(int ops) {
    if(!ops) return ;
    fac[0]=1; lg[0]=1;
    mu=(__int128)(((__int128)1)<<64)/mod;
    for(int i=1;i<N;i++) fac[i]=Mul(fac[i-1],base),lg[i]=Inc(fac[i],lg[i-1]);
    inv[N-1]=ksm(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i]=Mul(inv[i+1],base);
}

void modify(int x,int k) {
    for(int i=1;i<=len;i++) {
        sumFact[i][id[x]]=Dec(sumFact[i][id[x]],Mul(a[x],(x%i==0)));
        sumHash[i][id[x]]=Dec(sumHash[i][id[x]],Mul(a[x],fac[x%i]));
        sumFact[i][id[x]]=Inc(sumFact[i][id[x]],Mul(k,(x%i==0)));
        sumHash[i][id[x]]=Inc(sumHash[i][id[x]],Mul(k,fac[x%i]));
    }
    a[x]=(k%mod+2*mod)%mod;
    for(int i=L[id[x]];i<=R[id[x]];i++) preSB[id[x]][i]=Inc(preSB[id[x]][i-1],Mul(a[i],fac[i-1]));
    for(int i=1;i<=tot;i++) preB[i]=Inc(preB[i-1],preSB[i][R[i]]);


}
int queryHash(int l,int r,int k) {
    int res=0;
    if(k<=len) {
        if(id[l]==id[r]) {for(int i=l;i<=r;i++) res=Inc(res,Pos(i,k));return res;}
        for(int i=id[l]+1;i<=id[r]-1;i++) res=Inc(res,sumHash[k][i]);
        for(int i=l;i<=R[id[l]];i++) res=Inc(res,Pos(i,k));
        for(int i=L[id[r]];i<=r;i++) res=Inc(res,Pos(i,k));
        return res;
    }
    for(int i=0;i<=n;i+=k) {
        int lx=max(i,l),rx=min(i+k-1,r);

        if(lx>rx) continue;
        if(id[lx]==id[rx]) res=Inc(res,Mul(Dec(preSB[id[lx]][rx],preSB[id[lx]][lx-1]),Mul(inv[lx-1],fac[lx-l])));
        else {
            int cnt=0;
            cnt=Inc(cnt,Dec(preSB[id[lx]][R[id[lx]]],preSB[id[lx]][lx-1]));
            cnt=Inc(cnt,Dec(preB[id[rx]-1],preB[id[lx]]));
            cnt=Inc(cnt,Dec(preSB[id[rx]][rx],preSB[id[rx]][L[id[rx]]-1]));
            res=Inc(res,Mul(cnt,Mul(inv[lx-1],fac[lx-l])));
        }
    }
    return res;
}
int queryFact(int l,int r,int k) {
    int res=0;
    if(k<=len) {
        if(id[l]==id[r]) {
            for(int i=l;i<=r;i++) res=Inc(res,Mul(a[i],(i%k==0)));
            return res;
        }
        for(int i=id[l]+1;i<=id[r]-1;i++) res=Inc(res,sumFact[k][i]);
        for(int i=l;i<=R[id[l]];i++) res=Inc(res,Mul(a[i],(i%k==0)));
        for(int i=L[id[r]];i<=r;i++) res=Inc(res,Mul(a[i],(i%k==0)));
        return res;
    }
    for(int i=0;i<=n;i+=k) {
        if(l<=i && i<=r) res=Inc(res,Mul(a[i],(i%k==0)));
    }
    return res;
}
void init() {
    for(int i=1;i<=tot;i++) {
        preB[i]=preB[i-1];
        for(int j=L[i];j<=R[i];j++) {
            preB[i]=Inc(preB[i],Mul(a[j],fac[j-1]));
            preSB[i][j]=Inc(preSB[i][j-1],Mul(a[j],fac[j-1]));
        }
    }
    for(int i=1;i<=len;i++) {
        for(int j=1;j<=n;j++) {
            sumFact[i][id[j]]=0 ;
            sumHash[i][id[j]]=0;
        }
    }
    for(int i=1;i<=len;i++) {
        for(int j=1;j<=n;j++) {
            sumFact[i][id[j]]=Inc(sumFact[i][id[j]],Mul(a[j],(j%i==0)));
            sumHash[i][id[j]]=Inc(sumHash[i][id[j]],Mul(a[j],fac[j%i]));
        }
    }
}
signed main() {
    read(n,q);
    for(int i=1;i<=n;i++) read(a[i]),a[i]=(a[i]%mod+mod)%mod;
    init(1); len=sqrt(n); tot=n/len+(n%len>0);
    for(int i=1;i<=n;i++) {
        id[i]=(i-1)/len+1;
        if(!L[id[i]]) L[id[i]]=1e9;
        L[id[i]]=min(L[id[i]],i);
        R[id[i]]=max(R[id[i]],i);
    }
    init();
    int now=0;
    while(q--) {
        int ops;
        read(ops);
        if(ops==1) {
            int x,w;
            read(x,w);
            modify(x,w);

        } else {

            now++;
            /* init(); */
            //for(int i=1;i<=tot;i++) printf("%d ",preB[i]);
            // printf("\n");
            int l,r,m,res;
            read(l,r,m);
            res=(r-l+1);
            for(int i=1;i<=m;i++) {
                int x; read(x);
                res=__gcd(x,res);
            }
            int cnt1=queryHash(l,r,res);
            int cnt2=Mul(queryFact(l,r,res),lg[res-1]);
            if((cnt1%mod+2*mod)%mod==(cnt2%mod+2*mod)%mod) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
