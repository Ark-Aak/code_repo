#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 200050
#define Mx 500050
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
struct Edge{
	ll u,v,w;
	Edge(): u(0), v(0), w(0) {}
	Edge(ll _w,ll _v,ll _u): u(_u), v(_v), w(_w) {}
	bool operator<(Edge a){ return this->w < a.w; }
} e[Mx];
ll n,m,mn[Nx],mx[Nx],vis[Nx];
int main()
{
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	n=read(),m=read();
	rep(i,1,m) e[i]=Edge(read(),read(),read());
	sort(e+1,e+m+1);
	memset(mn,0x3f,sizeof(mn));
	drp(i,m,1){
		ll u=e[i].u,v=e[i].v;
		ll mn_u=mn[u],mn_v=mn[v];
		ll mx_u=mx[u],mx_v=mx[v];
		if(!vis[u]) mn[v]=min(mn_v,1ll);
		else mn[v]=min(mn[v],mx_u+1);
		if(!vis[v]) mn[u]=min(mn_u,1ll);
		else mn[u]=min(mn[u],mx_v+1);
		if(!vis[u]) mx[v]=max(mx_v,1ll);
		else mx[v]=max(mx[v],mn_u+1);
		if(!vis[v]) mx[u]=max(mx_u,1ll);
		else mx[u]=max(mx[u],mn_v+1);
		vis[u]=vis[v]=1;
	}
	rep(i,1,n) printf("%lld ",mx[i]);
	return 0;
}
