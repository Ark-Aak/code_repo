#include<bits/stdc++.h>
#define ll long long
#define N 800005
using namespace std;
const ll mod=1e9+7;
ll n,m,mi[N],mx[N],lc[N],rc[N],a[N],b[N];
map<ll,ll>mp;
void build(ll p,ll l,ll r){
    if(l==r){
        lc[p]=rc[p]=mi[p]=mx[p]=mp[a[l]];
        return ;
    }
    ll mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    mi[p]=min(mi[p<<1],mi[p<<1|1]);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
    lc[p]=lc[p<<1],rc[p]=rc[p<<1|1];
}
ll ask(ll p,ll l,ll r,ll x){
    if(mi[p]>=x)return 1;
    if(mx[p]<x)return 0;
    if(l==r)return lc[p]>=x;
    ll mid=(l+r)>>1;
    ll ans1=0,ans2=0;
    ans1=ask(p<<1,l,mid,x);
    ans2=ask(p<<1|1,mid+1,r,x);
    if(rc[p<<1]>=x&&lc[p<<1|1]>=x)return ans1+ans2-1;
    else return ans1+ans2;
}
void upd(ll p,ll l,ll r,ll x,ll y){
    if(x>r||x<l)return ;
    if(l==r&&l==x){
        lc[p]=rc[p]=mi[p]=mx[p]=y;
        return ;
    }
    ll mid=(l+r)>>1;
    if(x<=mid)upd(p<<1,l,mid,x,y);
    else upd(p<<1|1,mid+1,r,x,y);
    mi[p]=min(mi[p<<1],mi[p<<1|1]);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
    lc[p]=lc[p<<1],rc[p]=rc[p<<1|1];
}
struct query{
    ll op,x,y;
}q[N];
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
int main(){
    freopen("gaze.in","r",stdin);
    freopen("gaze.out","w",stdout);
    n=fr();
    m=fr();
    ll t=n;
    for(int i=1;i<=n;i++)a[i]=fr(),b[i]=a[i];   
    for(int i=1;i<=m;i++){
        q[i].op=fr();
        q[i].x=fr();
        if(q[i].op==1){
            b[++t]=q[i].x;
        }
        else {
            q[i].y=fr();
            b[++t]=q[i].y;
        }
    }
    sort(b+1,b+t+1);
    t=unique(b+1,b+t+1)-(b+1);
    for(int i=1;i<=t;i++)mp[b[i]]=i;
    build(1,1,n);
    for(int i=1;i<=m;i++){
        if(q[i].op==1)cout<<ask(1,1,n,mp[q[i].x])<<"\n";
        else upd(1,1,n,q[i].x,mp[q[i].y]);
    }
    return 0;
}