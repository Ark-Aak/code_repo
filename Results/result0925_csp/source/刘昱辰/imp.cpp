#include<bits/stdc++.h>
#define ll long long
#define N 2000515
using namespace std;
const double ftep=1e-7,step=50000,delt=0.995;
ll ans,T,n,a[N],cnt;
struct node{
    ll x,y,v;
}f[N];
ll getans(ll x,ll y){
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(f[i].x>=x&&f[i].y>=x&&f[i].x<=y&&f[i].y<=y){
            sum+=f[i].v;
        }
        if(f[i].x>y)break;
    }
    return sum-abs(y-x);
}
void sa(){
    ll x=1,y=cnt;
    ans=getans(x,y);
    for(double t=step;t>ftep;t*=delt){
        ll X=((ll)(((ll)y+2*rand()*t-RAND_MAX)))%cnt+1;
        ll Y=((ll)(((ll)x+2*rand()*t-RAND_MAX)))%cnt+1;
        if(X<1)X=1;
        if(X>cnt)X=cnt;
        if(Y<1)Y=1;
        if(Y>cnt)Y=cnt;
        if(X>Y)swap(X,Y);
        ll now=getans(a[X],a[Y]);
        if(now>ans){
            ans=now;
            x=X,y=Y;
        }else  if(exp((now-ans)/t)*RAND_MAX<rand())x=X,y=Y;
    }
}
bool cmp(node x,node y){
    return x.x<y.x;
}
inline ll mr(){
   ll x=0;bool fh=0;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
   return fh?-x:x;
}
int main(){
    freopen("imp.in","r",stdin);
    freopen("imp.out","w",stdout);
    srand(200801031);
    srand(rand());
    ans=INT_MIN;
    n=mr();
    for(int i=1;i<=n;i++){
        f[i].x=mr();
        f[i].y=mr();
        f[i].v=mr();
        a[++cnt]=f[i].x;
        a[++cnt]=f[i].y;
    }
    sort(a+1,a+cnt+1);
    sort(f+1,f+n+1,cmp);
    cnt=unique(a+1,a+cnt+1)-(a+1);
    while(((double)clock())<500)sa();
    cout<<ans<<endl;
    return 0;
}
