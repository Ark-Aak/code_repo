#include<bits/stdc++.h>
#define ll long long
#define N 400005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll n,qt,a[N],cnt;
struct qwq{
    ll ed,val;
};
vector<qwq> v[N];
namespace dij{
    priority_queue<pair<ll,ll> >q;
    bool vis[N];
    ll f[N];
    void sol(ll s){
        for(int i=1;i<=n;i++)f[i]=__LONG_LONG_MAX__,vis[i]=0;
        f[s]=0;
        q.push({0,s});
        while(!q.empty()){
            ll t=q.top().second;
            q.pop();
            if(vis[t])continue;
            vis[t]=1;
            for(auto i:v[t]){
                if(f[i.ed]>f[t]+i.val){
                    f[i.ed]=f[t]+i.val;
                    q.push({-f[i.ed],i.ed});
                }
            }
        }
    }
}
struct qu{
    ll x,y,id;
}q[N];
ll ans[N];
bool cmp(qu a,qu b){
    return a.x<b.x;
}
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("double.in","r",stdin);
    freopen("double.out","w",stdout);
    n=fr();
    for(int i=1;i<=n;i++){
        ll x=fr();
        v[2*i].push_back({2*i-1,x});
        v[2*i-1].push_back({2*i,x});
    }
    for(int i=1;i<n;i++){
        ll x=fr(),y=fr(),w1=fr(),w2=fr();
        v[2*x-1].push_back({2*y-1,w1});
        v[2*y-1].push_back({2*x-1,w1});
        v[2*x].push_back({2*y,w2});
        v[2*y].push_back({2*x,w2});
    }
    qt=fr();
    n<<=1;
    for(int i=1;i<=qt;i++){
        q[i].x=fr();q[i].y=fr();
        if(q[i].x>q[i].y)swap(q[i].x,q[i].y);
        q[i].id=i;
        a[++cnt]=q[i].x;
    }
    sort(q+1,q+qt+1,cmp);
    sort(a+1,a+cnt+1);
    cnt=(unique(a+1,a+cnt+1)-(a+1));
    ll ind=1;
    for(int i=1;i<=cnt;i++){
        dij::sol(a[i]);
        while(q[ind].x==a[i]){
            ans[q[ind].id]=dij::f[q[ind].y];
            ind++;
        }
    }
    for(int i=1;i<=qt;i++)cout<<ans[i]<<endl;
    return 0;
}