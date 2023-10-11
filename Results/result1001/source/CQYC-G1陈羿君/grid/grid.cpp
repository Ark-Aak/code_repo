#include <bits/stdc++.h>
using namespace std;
#define int long long
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return x*f;
}
int q,n,m;
signed main(){
    freopen("grid.in","r",stdin);
    freopen("grid.out","w",stdout);
    q=read();
    while(q--){
        n=read(),m=read();
        if(n<m) swap(n,m);
        cout<<m*n*n*(n-1)/2+m*n*((n*(n+1)*(n+1)/2)-n-n*(n+1)*(2*n+1)/6)<<"\n";
    }
    return 0;
}