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
const int N=505,mod=998244353;
int fac[N],inv[N];
int ksm(int x,int y) {
    int ans=1;
    while(y) {
        if(y&1) ans=(1ll*ans*x)%mod;
        x=(1ll*x*x)%mod; y>>=1;
    }
    return ans;
}
inline int Inc(int x,int y) {return x+y<mod?x+y:x+y-mod;}
inline int Dec(int x,int y) {return x>=y?x-y:x-y+mod;}
inline int Mul(int x,int y) {return (1ll*x*y)%mod;}
inline int C(int x,int y) {
    if(x<y || x<0 || y<0) return 0;
    return Mul(fac[x],Mul(inv[y],inv[x-y]));
}
int n,K;
map<int,int> ma;
signed main() {
    read(n,K);
    for(int i=0;i<(1<<n);i++) {
        if(__builtin_popcount(i)!=2*K) continue;
        int sum=0,tot=0,sum1=0,sum2=0;
        for(int j=0;j<n;j++) {
            if(!((i>>j)&1)) continue;
            tot++;
            if(tot<=K) sum-=(j+1),sum1++;
            else sum+=(j+1),sum2++;
        }
        ma[sum]++;
    }
    for(auto i:ma) printf("%d ",i.second);
    return 0;
}
