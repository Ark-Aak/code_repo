#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 10
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
ll a[Nx],n,m,ans;
inline void dfs(ll x,ll now,ll cnt){
	if(x>n) return (void)(ans++);
	rep(i,1,m){
		if(i==now&&cnt+1<=a[i]) dfs(x+1,i,cnt+1);
		if(i!=now&&a[i]) dfs(x+1,i,1);
	}
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
    n=read(),m=read();
    rep(i,1,m) a[i]=read();
    dfs(1,0,0);
    printf("%lld",ans);
	return 0;
}
