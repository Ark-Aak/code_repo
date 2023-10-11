//3s 512M
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

const int Maxn=5e5+10;
int N,Q,L[Maxn],R[Maxn],M,A[Maxn],Mx,X[Maxn];
bool f;
vector<int> V[Maxn];

void Solve0(){
    For(i,1,N) For(j,L[i],R[i]) V[j].pb(i);
    while(Q--){
        M=read(); int tot=0;
        For(i,1,M){
            X[i]=read(); int len=V[X[i]].size();
            For(j,0,len-1){
                if(A[V[X[i]][j]]&1) --tot;
                else ++tot;
                ++A[V[X[i]][j]];
            }
        }
        For(i,1,M){
            int len=V[X[i]].size();
            For(j,0,len-1) --A[V[X[i]][j]];
        }
        write(tot),pc('\n');
    }
}

int main(){
    freopen("badge.in","r",stdin);
    freopen("badge.out","w",stdout);
    N=read(),Q=read();
    For(i,1,N){
        L[i]=read(),R[i]=read(),Mx=max(Mx,R[i]);
        if(R[i]-L[i]>5) f=1;
    }
    if(!f) Solve0(),exit(0);
    while(Q--){
        M=read(); int x,tot=0;
        For(i,1,Mx) A[i]=0;
        For(i,1,M) x=read(),++A[x];
        For(i,1,Mx) A[i]+=A[i-1];
        For(i,1,N) if((A[R[i]]-A[L[i]-1])&1) ++tot;
        write(tot),pc('\n');
    }
    return 0;
}