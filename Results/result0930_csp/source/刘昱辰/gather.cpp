#include<bits/stdc++.h>
#define ll long long
#define N 300005
#define endl "\n" 
using namespace std;
ll n,ans1,ans2,cnt,q[N],vis[N];
vector <ll> v[N];
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
int main(){
    freopen("gather.in","r",stdin);
    freopen("gather.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        v[x].push_back(i);
        if(++vis[x]==2)q[++cnt]=x;
    }
    for(int i=1;i<=cnt;i++){
        for(int j=0;j<v[q[i]].size()-1;j++){
            ans1+=(n-v[q[i]][j+1]+1),ans2+=v[q[i]][0]-1;
        }
    }
    cout<<n*(n-1)/2-ans1-ans2;
    return 0;
}