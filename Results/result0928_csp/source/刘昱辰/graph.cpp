#include<bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;
const ll mod=1e9+7;
ll n,fa[N],ans;
struct qwq{
    ll x,y;
}f[N];
priority_queue<pair<ll,ll> >q;
ll fatherfind(ll x){
    return x==fa[x]?x:fa[x]=fatherfind(fa[x]);
}
void gay(ll x,ll y){
    x=fatherfind(x),y=fatherfind(y);
    if(x!=y)fa[x]=y;
}
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
bool cmp(qwq a,qwq b){
    return a.x==b.x?a.y<b.y:a.x<b.x;
}
int main(){
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        fa[i]=i;
        f[i].x=fr();
        f[i].y=fr();
    }
    sort(f+1,f+n+1,cmp);
    ll t=INT_MIN;
    for(int i=1;i<=n;i++)q.push(make_pair(f[i].y,i));
    while(!q.empty()){
        ll x=q.top().first,id=q.top().second;
        q.pop();
        if(id<t)continue;
        t=id;
        for(int i=1;i<=id;i++){
            if(f[i].y<=x){
                gay(i,id);
            }
        }
    }
    for(int i=1;i<=n;i++)if(fatherfind(i)==i)ans++;
    cout<<ans;
    return 0;
}