#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
const ll mod=1e9+7;
ll n,m,a[N];
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
int main(){
    freopen("easiest.in","r",stdin);
    freopen("easiest.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)a[i]=fr();
    while(m--){
        ll op=fr(),l1=fr(),r1=fr(),l2=fr(),r2=fr();
        if(op==2){
            cout<<"1\n";
            continue;
        }
        ll ans=0;
        ans+=l2-l1;
        ll t=a[r2];
        for(int i=r2+1;i<=r1;i++){
            if(a[i]<=t){
                ans++;
            }else t=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}