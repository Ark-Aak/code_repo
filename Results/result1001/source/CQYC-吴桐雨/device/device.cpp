//1s 512M
#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
#define pb push_back
#define mp make_pair
#define int long long
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

int T,K,N,Ans;

void Solve(){
    K=read(),N=read();
    int a=K/100,b=K/10%10,c=K%10;
    if(a==b&&b==c) return puts("1"),void();
    if(!N) return puts("1"),void();
    if(a==b||a==c||b==c){
        if(N==1) puts("7");
        else puts("8");
        return;
    }
    if(N==1) puts("24");
    else puts("27");
}

signed main(){
    freopen("device.in","r",stdin);
    freopen("device.out","w",stdout);
    T=read(); while(T--) Solve();
    return 0;
}
/*
(1) a=b=c ---> 1
111 4              1
111 148923165      1
999 100            1

(2) n=0 ---> 1
123 0              1
275 0              1
846 0              1
144 0              1
377 0              1
325 0              1

(3) a=b≠c && n=1 ---> 7
121 1              7
767 1              7

(4) a=b≠c && n>1 ---> 8
955 7              8
288 10             8
663 369991700      8
575 4              8
255 374055408      8
443 7              8

(5) n=1 ---> 24
123 1              24

(6) n>1 ---> 27
739 199009435      27
687 4              27
348 387697943      27
659 3              27

*/