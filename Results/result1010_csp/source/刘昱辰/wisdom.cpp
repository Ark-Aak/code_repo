#include<bits/stdc++.h>
#define ll long long
#define N 2000005
#define inv2 500000004
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll n,m,k,fa[N],fb[N],cnta,cntb;
ll ans=0;
struct qwq{
    ll b,id;
}b[N],a[N];
bool cmp(qwq x,qwq y){
    if(x.b==1)return 0;
    if(y.b==1)return 1;
    return x.b<y.b;
}
void sol(){
    for(int i=1;i<=n;i++)ans=(ans+a[i].b*fa[i]+mod)%mod;
    for(int i=1;i<=m;i++)ans=(ans+(b[i].b-1)%mod*fb[i]%mod+mod)%mod;
    sort(b+1,b+m+1,cmp);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m;i++){
        if(b[i].b==1)break;
        for(int j=1;j<=n;j++){
            ll t=(a[j].id-1)*m+b[i].id;
            ans=(ans+((b[i].b*a[j].b%mod)-a[j].b-b[i].b+1+mod)%mod*t%mod)%mod;
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("wisdom.in","r",stdin);
    freopen("wisdom.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)a[i]={1,i},fa[i]=(1+(i-1)*m%mod+i*m%mod)*m%mod*inv2%mod;
    for(int i=1;i<=m;i++)b[i]={1,i},fb[i]=(2*i+(n-1)*m%mod)%mod*n%mod*inv2%mod;
    for(int i=1;i<=k;i++){
        ll x,y;
        char op;
        cin>>op>>x>>y;
        if(op=='R')a[x].b=a[x].b*y%mod,cnta++;
        if(op=='S')b[x].b=b[x].b*y%mod,cntb++;
    }
    sol();
    return 0;
}