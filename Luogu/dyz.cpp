#include<bits/stdc++.h>

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
const int N=1e6+5,base=998244353,mod=1e9+7;
int n,fac[N],inv[N];
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
inline int Mul(int x,int y) {return reduce(1ll*x*y);}
inline void init(int ops) {
    mu=(__int128)(((__int128)1)<<64)/mod;
    if(!ops) return ;
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=Mul(fac[i-1],base);
    inv[N-1]=ksm(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i]=ksm(ksm(base,i),mod-2);
}
struct BIT {
    int pre[N];
    inline int lowbit(int x) {return x&(-x);}
    inline void add(int x,int k) {
        for(int i=x;i<=n;i+=lowbit(i)) pre[i]=Inc(pre[i],k);
    }
    inline int query(int x) {
        int cnt=0;
        for(int i=x;i;i-=lowbit(i)) cnt=Inc(cnt,pre[i]);
        return cnt;
    }
}T1,T2;
signed main() {
    init(1);
    int Test;
    read(Test);
    while(Test--) {
        read(n);
        for(int i=1;i<=n;i++) T1.pre[i]=T2.pre[i]=0;
        int fl=0;
        for(int i=1;i<=n;i++) {
            int x; read(x);
            if(fl) continue;
            T1.add(x,fac[x]);
            T2.add(n-x+1,fac[n-x+1]);
            int len=min(x-1,n-x);
            int f1=Mul(Dec(T1.query(x),T1.query(x-len-1)),inv[x-len-1]);
            int f2=Mul(Dec(T2.query(n-x+1),T2.query(n-(x+len))),inv[n-(x+len)]);
            if(f1!=f2) fl=1;
        }
        if(fl) puts("Y");
        else puts("N");
    }
    return 0;
}
/*
2
3
1 3 2
3
3 2 1


*/
