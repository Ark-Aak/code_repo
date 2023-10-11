#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll n,root,m;
ll val[N],lzy[N],t;
ll dep[N],fa[N],top[N],bel[N],siz[N],cnt,son[N],c[N],pos[N];
vector<ll> v[N];
void dfs1(ll x,ll fat,ll d){
    dep[x]=d;
    fa[x]=fat;
    siz[x]=1;
    ll maxs=-1;
    for(auto i:v[x]){
        if(i==fat)continue;
        dfs1(i,x,d+1);
        siz[x]+=siz[i];
        if(siz[i]>maxs)son[x]=i,maxs=siz[i];
    }
}
void dfs2(ll x,ll tp){
    top[x]=tp;
    bel[x]=++cnt;
    if(son[x])dfs2(son[x],tp);
    for(auto i:v[x]){
        if(i==fa[x]||i==son[x])continue;
        dfs2(i,i);
    }
}
void lt(ll p,ll len,ll x){
    lzy[p]=x;
    val[p]=len*x;
}
void pushdown(ll p,ll l,ll r,ll mid){
    if(lzy[p]==0)return ;
    lt(p<<1,mid-l+1,lzy[p]);
    lt(p<<1|1,r-mid,lzy[p]);
    lzy[p]=0;
}
void upd(ll p,ll l,ll r,ll le,ll ri,ll x){
    if(le<=l&&ri>=r){
        lt(p,r-l+1,x);
        return ;
    }
    ll mid=(l+r)>>1;
    pushdown(p,l,r,mid);
    if(le<=mid)upd(p<<1,l,mid,le,ri,x);
    if(ri>mid) upd(p<<1|1,mid+1,r,le,ri,x);
    val[p]=val[p<<1]+val[p<<1|1];
}
ll ask(ll p,ll l,ll r,ll le,ll ri){
    if(le<=l&&ri>=r)return val[p];
    ll mid=(l+r)>>1;
    pushdown(p,l,r,mid);
    ll ans=0;
    if(le<=mid)ans+=ask(p<<1,l,mid,le,ri);
    if(ri>mid) ans+=ask(p<<1|1,mid+1,r,le,ri);
    return ans;
}
void rch(ll x,ll y,ll z){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        upd(1,1,cnt,bel[top[x]],bel[x],z);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    upd(1,1,cnt,bel[x],bel[y],z);
}
ll rque(ll x,ll y){
    ll ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        ans+=ask(1,1,cnt,bel[top[x]],bel[x]);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    ans+=ask(1,1,cnt,bel[x],bel[y]);
    return ans;
}
ll lca(ll x,ll y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}

bool updpos(ll p,ll l,ll r,ll le,ll ri,ll x){
    if(le<=l&&ri>=r){
        if(pos[p]==-x)return 1;
        pos[p]=x;
        if(l==r)return 0;
        if(pos[p<<1]==-x)return 1;
        if(pos[p<<1|1]==-x)return 1;
        pos[p<<1]=x;
        pos[p<<1|1]=x;
        return 0;
    }
    ll mid=(l+r)>>1;
    ll ans1=0,ans2=0;
    if(le<=mid)ans1=updpos(p<<1,l,mid,le,ri,x);
    if(ri>mid)ans2=updpos(p<<1|1,mid+1,r,le,ri,x);
    if(ans1==1||ans2==1)return 1;
    return 0;
}
bool rpos(ll x,ll y,ll z){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        if(updpos(1,1,cnt,bel[top[x]],bel[x],z))return 1;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    if(updpos(1,1,cnt,bel[x]+1,bel[y],z))return 1;
    return 0;
}



struct que{
    ll l,r,len,lca;
}q[N];
void cln(){
    for(int i=0;i<=n;i++){
        son[i]=dep[i]=fa[i]=siz[i]=0;
        v[i].clear();
    }
    for(int i=1;i<=m;i++)q[i]={0,0,0,0};
    for(int i=0;i<=2*cnt;i++)top[i]=bel[i]=val[i]=lzy[i]=pos[i]=0;
    cnt=n=m=0;
}
bool cmp(que a,que b){
    return a.len>b.len;
}
void solve(){
    ll fl=0;
    cln();
    cin>>n;
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        if(x!=i||y!=i+1)fl=1;
    }
    dfs1(1,0,1);
    dfs2(1,1);
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].lca=lca(q[i].l,q[i].r);
        q[i].len=dep[q[i].r]+dep[q[i].l]-2*dep[q[i].lca]+1;
    }
    sort(q+1,q+m+1,cmp);
    for(int i=1;i<=m;i++){
        ll qt=rque(q[i].l,q[i].r);
        if(qt==q[i].len){
            cout<<"No\n";
            return ;
        }
        rch(q[i].l,q[i].r,1);
        if(fl==0&&(rpos(q[i].l,q[i].lca,1)||rpos(q[i].lca,q[i].r,-1))){
            cout<<"No\n";
            return ;
        }
    }
    cout<<"Yes\n";
}
int main(){
    freopen("robot.in","r",stdin);
    freopen("robot.out","w",stdout);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
