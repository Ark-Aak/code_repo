#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,m,type,l1,r1,l2,r2,dol;
int a[100050],num[100050];
int sgtree[100050],fa[21][100050];
ll sum[21][100050],cnt,cnt2,snum,temp;
ll deep[100050],dsum[21][100050];
int siz[21][100050];
int lbound[21][100050];
int lowbit(int x){return x&-x;}
void add(int x,int delt){for (;x<=n;x+=lowbit(x)) sgtree[x]=min(sgtree[x],delt);}
int get(int x,int ans=inf){for (;x;x-=lowbit(x)) ans=min(ans,sgtree[x]);return ans;}
int getop(int x,int r){
    int out=0;
    for (int i=20;i>=0;--i)
        if(fa[i][x]&&fa[i][x]<=r) x=fa[i][x],out+=(1<<i);
    return out;
}
ll getback(int x,int l,ll qwq[][100050]){
    ll out=0;snum=0;
    for (int i=20;i>=0;--i)
        if(lbound[i][x]>=l) 
            out+=qwq[i][x],
            snum+=siz[i][x],
            x=lbound[i][x]-1;
    dol=x+1;
    return out;
}
int main(){
    freopen("easiest.in","r",stdin);
    freopen("easiest.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    memset(sgtree,0x3f,sizeof(sgtree));
    for (int i=n;i>=1;--i){
        fa[0][i]=get(n+1-a[i]);
        if(fa[0][i]==inf) fa[0][i]=0;
        add(n+1-a[i],i);
    }
    for (int i=1;i<=n;++i)
        num[i]++,num[fa[0][i]]+=num[i];
    for (int i=n;i>=1;--i)
        deep[i]=deep[fa[0][i]]+1;
    for (int i=1;i<=n;++i){
        dsum[0][i]+=deep[i];
        if(fa[0][i]) dsum[0][fa[0][i]]+=dsum[0][i];
    }
    for (int i=1;i<=n;++i){
        siz[0][i]=num[i];
        sum[0][i]=dsum[0][i]-1LL*deep[i]*num[i]-num[i]+1;
        lbound[0][i]=i-num[i]+1;
    }
    for (int i=n;i>=1;--i)
        for (int k=1;k<=20;++k)
            fa[k][i]=fa[k-1][fa[k-1][i]];
    for (int i=1;i<=n;++i)
        for (int k=1;k<=20;++k)
            lbound[k][i]=lbound[k-1][lbound[k-1][i]-1],
            sum[k][i]=sum[k-1][i]+sum[k-1][lbound[k-1][i]-1],
            dsum[k][i]=dsum[k-1][i]+dsum[k-1][lbound[k-1][i]-1],
            siz[k][i]=siz[k-1][i]+siz[k-1][lbound[k-1][i]-1];
    for (int i=1;i<=m;++i){
        scanf("%d%d%d%d%d",&type,&l1,&r1,&l2,&r2);
        if(type==1){
            cnt=getop(r2,r1);
            printf("%d\n",r1-l1-r2+l2-cnt);
        }
        else {
            cnt2=0;
            cnt=getback(r2,l2,sum);
            if(dol!=l2){
                cnt+=sum[0][dol-1];temp=dol-1;
                dol=lbound[0][dol-1];
                cnt2=getback(l2-1,dol,dsum);
                cnt2=cnt2-1LL*deep[temp]*snum-snum;
            }
            printf("%lld\n",1LL*(r2-l2+1)*(r2-l2)/2-cnt+cnt2);
        }
    }
    return 0;
}
