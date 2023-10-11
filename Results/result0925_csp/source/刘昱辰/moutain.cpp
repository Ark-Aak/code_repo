#include<bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;
ll f[N],n,a[N],le[N],ri[N];
inline ll mr(){
   ll x=0;bool fh=0;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
   return fh?-x:x;
}
int main(){
    freopen("moutain.in","r",stdin);
    freopen("moutain.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)f[i]=mr();
    for(int i=1;i<=n;i++){
        ll l=i-1,r=i+1;
        while(l>=1&&f[l]<=f[i])a[i]++,l--;
        while(r<=n&&f[r]<=f[i])a[i]++,r++;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<endl;
    return 0;
}