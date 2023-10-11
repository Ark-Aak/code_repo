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

int T,A[7];

int calc(int x,int y,int z,int a,int b,int c){
    int t1=a-x,t2=b-y,t3=c-z,l=(t1?t1:t2?t2:t3);
    if((!t1||t1==l)&&(!t2||t2==l)&&(!t3||t3==l)) return 1;
    if(!t1||!t2||!t3) return 2;
    if(t1==t2||t1==t3||t2==t3) return 2;
    A[1]=t1,A[2]=t2,A[3]=t3; sort(A+1,A+4);
    if(A[2]==A[1]+A[3]) return 2;
    return 3;
}

int calc2(int x,int y,int z,int a,int b,int c){
    if(!x||!y||!z) return 5;
    if(a%x!=0||b%y!=0||c%z!=0) return 5;
    int t1=a/x,t2=b/y,t3=c/z;
    if(t1==t2&&t2==t3) return 1;
    if(t1==t2||t1==t3||t2==t3) return 2;
    return 3;
}

void Solve(){
    int x=read(),y=read(),z=read();
    int a=read(),b=read(),c=read();
    if(x==a&&y==b&&z==c) return puts("0"),void();

    //only add
    int ans=calc(x,y,z,a,b,c);
    //only mul
    int tmp=calc2(x,y,z,a,b,c);
    //add & mul

    //mul & add


    // cerr<<ans<<" "<<tmp<<"\n";

    write(min(ans,tmp)),pc('\n');
}

int main(){
    freopen("triple.in","r",stdin);
    freopen("triple.out","w",stdout);
    T=read(); while(T--) Solve();
    return 0;
}
/*
2
-9 -10 -4
0 4 0
-1 -3 -1
10 -10 4

1
-4 5 6
-3 -3 3
*/