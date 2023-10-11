#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+2;
int n,Q;
int l[maxn],r[maxn];
int m,x[maxn],sum[maxn];
int read(){
    int x=0;
    bool f=0;
    char ch=getchar();
    while(!isdigit(ch))f=((ch=='-')?1:0),ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return (f)?-x:x;
}
int main(){
    freopen("badge.in","r",stdin);
    freopen("badge.out","w",stdout);
    n=read(),Q=read();
    for(int i=1;i<=n;i++)l[i]=read(),r[i]=read();
    for(int i=1;i<=Q;i++){
        for(int j=1;j<=n;j++)sum[j]=0;
        m=read();
        for(int j=1;j<=m;j++)x[j]=read(),sum[x[j]]++;
        for(int j=1;j<=n;j++)sum[j]+=sum[j-1];
        int ans=0;
        for(int j=1;j<=n;j++)ans+=((sum[r[j]]-sum[l[j]-1])%2==1);
        printf("%d\n",ans);
    }
    return 0;
}