//1s 512M
#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
#define pb push_back
#define mp make_pair
#define ls (id<<1)
#define rs ((id<<1)|1)
#define mid ((l+r)>>1)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)

int read(){
    int ret=0,f=0; char ch=gc();
    while(ch<'0'||ch>'9') f|=(ch=='-'),ch=gc();
    while(ch>='0'&&ch<='9') ret=(ret<<1)+(ret<<3)+(ch^48),ch=gc();
    return f?-ret:ret;
}

void write(int x){
    if(!x) return pc('0'),void();
    if(x<0) pc('-'),x=-x;
    int stk[30],tp=0;
    while(x) stk[++tp]=x%10,x/=10;
    while(tp) pc('0'+stk[tp--]);
    return;
}

int T,N,M;

void Solve(){
    N=read(),M=read();
    if(N==1||M==1) return puts("0"),void();
    if(M<N) swap(N,M);
    int ans=1;
    For(i,1,M) ans*=(i+2);
    write(ans),pc('\n');
}

int main(){
    freopen("grid.in","r",stdin);
    freopen("grid.out","w",stdout);
    T=read(); while(T--) Solve();
    return 0;
}