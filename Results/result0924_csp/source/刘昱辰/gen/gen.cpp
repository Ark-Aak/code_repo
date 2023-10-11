#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
ll n,m,d[N],ans;
const ll mod=1e9+7;
map<ll,ll> mp;
inline ll mr(){
   ll x=0;bool fh=0;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
   return fh?-x:x;
}
int main(){
    freopen("gen.in","r",stdin);
    freopen("gen.out","w",stdout);
    n=mr(),m=mr();
    for(int i=1;i<=m;i++){
        ll x,y;
        x=mr(),y=mr();
        d[x]++,d[y]++;
    }
    for(int i=1;i<=n;i++)mp[d[i]]++;
    sort(d+1,d+n+1);
    ll cnt=(unique(d+1,d+n+1)-(d+1));
    for(int i=1;i<=cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            ans=(ans+mp[d[j]]*mp[d[i]]*(d[i]^d[j])*(d[i]|d[j])*(d[i]&d[j])%mod)%mod;
        }
    }
    cout<<ans;
    return 0;
}