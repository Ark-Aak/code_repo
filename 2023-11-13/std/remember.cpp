#include <bits/stdc++.h>
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return x*f;
}
const int N=2005,M=6005,mod=147744151;
#define t(x) (x==0?1:-1)
int n,m1,m2,a[N],b[N],g[2][N][11],f[2][N][11],ans,jc[M],ijc[M];
#define pow Pow
int pow(int x,int base){
    int ans=1;
    while(base){
        if(base&1) ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        base>>=1;
    }
    return ans;
}
int len(int x){
    return to_string(x).size();
}
void add(int &x,int y){
    x=(x+y)%mod;
}
int C(int n,int m){
    if(n>m||m<0||n<0) return 0;
    return 1ll*jc[m]*ijc[n]%mod*ijc[m-n]%mod;
}
void init(int n){
    jc[0]=1;
    for(int i=1;i<=n;i++) jc[i]=1ll*jc[i-1]*i%mod;
    ijc[n]=pow(jc[n],mod-2);
    for(int i=n-1;~i;i--) ijc[i]=1ll*ijc[(i+1)]*((i+1))%mod;
}
int gb(int n,int m){
    if(m==0) return n==0;
    return C(m-1,m+n-1);
}
void solve(){
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    m1=m2=ans=0;
    n=read();
    for(int i=1;i<=n;i++){
        int x=read();
        if(len(x)&1) a[++m1]=x%11;
        else b[++m2]=x%11;
    }
    f[0][0][0]=1;
    for(int i=0;i<m1;i++){
        memset(f[(i+1)&1],0,sizeof(f[(i+1)&1]));
        for(int j=0;j<=i;j++){
            for(int k=0;k<11;k++){
                int now=f[i&1][j][k];
                add(f[(i+1)&1][j+1][(k-a[(i+1)]+11)%11],now);
                add(f[(i+1)&1][j][(k+a[(i+1)])%11],now);
            }
        }
    }
    g[0][0][0]=1;
    for(int i=0;i<m2;i++){
        memset(g[(i+1)&1],0,sizeof(g[(i+1)&1]));
        for(int j=0;j<=i;j++){
            for(int k=0;k<11;k++){
                int now=g[i&1][j][k];
                add(g[(i+1)&1][j+1][(k-b[(i+1)]+11)%11],now);
                add(g[(i+1)&1][j][(k+b[(i+1)])%11],now);
            }
        }
    }
    for(int i=0;i<=m2;i++){
        for(int j=0;j<11;j++){
            int k=(11-j)%11;
            int res=1ll*jc[m1/2]*jc[m1-m1/2]%mod*jc[i]%mod*jc[m2-i]%mod*gb(i,m1-m1/2)%mod*gb(m2-i,m1/2+1)%mod*g[m2&1][i][j]%mod*f[m1&1][m1/2][k]%mod;
            add(ans,res);
        }
    }
    cout<<ans<<"\n";
}
int T;
int main(){
    freopen("remember.in","r",stdin);
    freopen("remember.out","w",stdout);
    T=read();
    init(6000);
    while(T--) solve();
    return 0;
}
