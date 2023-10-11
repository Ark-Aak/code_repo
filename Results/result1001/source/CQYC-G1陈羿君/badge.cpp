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
const int N=5e5+5;
int n,m;
struct sg{
    int l,r;
}a[N];
namespace nm{
    int t[N],laz[N],T;
    int lowbit(int x){
        return x&-x;
    }
    void add(int x,int c){
        while(x<=n){
            if(laz[x]!=T) t[x]=0,laz[x]=T;
            t[x]+=c;
            x+=lowbit(x);
        }
    }
    int ask(int x){
        int ans=0;
        while(x){
            if(laz[x]!=T) t[x]=0,laz[x]=T;
            ans+=t[x];
            x-=lowbit(x);
        }
        return ans;
    }
    int main(){
        while(m--){
            T++;
            int k=read(),ans=0;
            while(k--){
                int x=read();
                add(x,1);
            }
            for(int i=1;i<=n;i++) ans+=(ask(a[i].r)-ask(a[i].l-1))&1;
            cout<<ans<<"\n";
        }
        return 0;
    }
}
namespace lr5{
    int cnt,t[N],laz[N],T;
    struct ss{
        int l,r,v;
    }s[N];
    bool operator <(ss a,ss b){
        return a.l<b.l;
    }
    map<long long,int> tt,dd;
    long long chh(sg x){
        return 1ll*n*x.l+1ll*x.r;
    }
    int main(int kkk){
        for(int i=1;i<=n;i++){
            int k=chh(a[i]);
            if(tt[k]==0) dd[k]=++cnt;
            tt[k]++;
            s[dd[k]]={a[i].l,a[i].r,tt[k]};
        }
        n=cnt;
        sort(s+1,s+n+1);
        while(m--){
            int k=read(),ans=0;
            T++;
            while(k--){
                int x=read();
                int pos=lower_bound(s+1,s+n+1,(ss){x-kkk,0,0})-s;
                while(s[pos].l<=x&&pos<=n){
                    if(s[pos].r>=x){
                        if(laz[pos]!=T) laz[pos]=T,t[pos]=0;
                        t[pos]++;
                        if(t[pos]&1) ans++;
                        else ans--;
                    }
                    pos++;
                }
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
}
signed main(){
    freopen("badge.in","r",stdin);
    freopen("badge.out","w",stdout);
    n=read(),m=read();
    int c=0;
    for(int i=1;i<=n;i++){
        a[i].l=read(),a[i].r=read();
        c=max(c,a[i].r-a[i].l+1);
    }
    if(n*m<=1e8) nm::main();
    else lr5::main(c);
    return 0;
}