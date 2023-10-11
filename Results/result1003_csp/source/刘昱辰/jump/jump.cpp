#include<bits/stdc++.h>
#define ll long long
#define N 600005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll n,a[N],f[N];
stack<ll>q;
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    n=fr();
    for(int i=1;i<=n;i++){
        a[i]=fr();
        while(!q.empty()&&a[i]>=a[q.top()])q.pop();
        if(q.empty())f[i]=1;
        else f[i]=f[q.top()]+1;
        q.push(i);
    }
    for(int i=1;i<=n;i++)cout<<f[i]<<" ";
    return 0;
}