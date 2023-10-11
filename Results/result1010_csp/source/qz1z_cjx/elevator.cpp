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
const ll inf=LONG_LONG_MAX;
ll n,k,siz[10000],mx[10000],a[10000],tot,ans=inf;
ll lowbit(ll x){return x&(-x);}
ll dfs(ll P,ll sum,ll t){
	if(!siz[P]) return ans=min(ans,sum);
	if(sum>=ans) return inf;
	ll res=inf;
	rep(S,1,tot) {
		if(((S&P)<S)||siz[S]>k) continue;
		res=min(res,dfs(P^S,sum+(t+(mx[S]-1)*2)*siz[S],t+(mx[S]-1)*2));
	}
	return res;
}
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	n=read(),k=read();
	rep(i,1,n) a[1ll<<(i-1)]=read();
	tot=(1ll<<n)-1;
	rep(S,1,tot){
		siz[S]=siz[S-lowbit(S)]+1;
		mx[S]=max(mx[S-lowbit(S)],a[lowbit(S)]);
	}
	printf("%lld",dfs(tot,0,0));
	return 0;
}
