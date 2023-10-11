#include<bits/stdc++.h>
#define ll long long
#define N 400005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll n,fa[N];
struct qwq{
    ll c,x1,y1,x2,y2;
}q[N];
ll fd(ll x){
    return fa[x]==x?x:(fa[x]=fd(fa[x]));
}
void merge(ll x,ll y){
    x=fd(x),y=fd(y);
    if(x!=y)fa[x]=y;
}
bool cmp(qwq a,qwq b){
    return a.c<b.c;
}
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    n=fr();
    for(int i=1;i<=2*n;i++)fa[i]=i;
    for(int i=1;i<=n;i++){
        q[i].c=fr();q[i].x1=fr();q[i].y1=fr();q[i].x2=fr();q[i].y2=fr();
        merge(q[i].x1,q[i].y1);
        merge(q[i].x2,q[i].y2);
    }
    ll cnt=0;
    for(int i=1;i<=2*n;i++)if(fd(i)==i)cnt++;
    sort(q+1,q+n+1,cmp);
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(fd(q[i].x1)!=fd(q[i].x2)){
            cnt--;
            ans+=q[i].c;
            merge(q[i].x1,q[i].x2);
        }
        if(cnt==0)break;
    }
    cout<<ans;
    return 0;
} 
